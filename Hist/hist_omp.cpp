#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <omp.h>

using namespace std;

#define NBUCKETS 10
#define NVALS 20//10000000

template <typename T>
void print_arr(int n,T *arr){

	for(int i=0; i<n;i++)
		cout<<arr[i]<<" ";

	cout<<endl;
}

void init_arr(float *arr){

	srand(0);

	for(int i=0;i<NVALS;i++){
		arr[i] = (rand()/(float)RAND_MAX)*10.0;
	}

}

int sample(float a){

	int val =(int)a%NBUCKETS;
	// cout<<val<<endl;

	return val;
}

void histogram(float *arr){

	int hist[NBUCKETS];
	omp_lock_t hist_locks[NBUCKETS];

	cout<<"Number of Threads: "<<omp_get_num_threads()<<endl;

#pragma omp parallel
{ 
// #pragma omp single nowait
// {
// 		cout<<"Number of Threads: "<<omp_get_num_threads()<<endl;
// }		
#pragma omp for
	for(int i=0;i<NBUCKETS;i++){
		omp_init_lock(&hist_locks[i]);
		hist[i]=0;
	}
}
#pragma omp parallel for
	for(int i=0;i<NVALS;i++){
		int ival= (int) sample(arr[i]);
		omp_set_lock(&hist_locks[ival]);
		hist[ival]++;
		omp_unset_lock(&hist_locks[ival]);
	}

	for(int i=0;i<NBUCKETS;i++){
		omp_destroy_lock(&hist_locks[i]);
	}


	print_arr(NBUCKETS,hist);
}


int main(){
	cout<<"Histogram OMP"<<endl;
	float *A;

	A=(float*)malloc(sizeof(float)*NVALS);

	init_arr(A);
	// print_arr(NVALS,A);
	histogram(A);
	cout<<"Max thread "<<omp_get_max_threads()<<endl;
	free(A);
	return 0;
}
