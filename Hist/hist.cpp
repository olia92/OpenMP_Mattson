#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <omp.h>

using namespace std;

#define NBUCKETS 10
#define NVALS 10000000

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

	for(int i=0;i<NBUCKETS;i++){
		hist[i]=0;

	}

	for(int i=0;i<NVALS;i++){
		int ival= (int) sample(arr[i]);
		hist[ival]++;
	}

	print_arr(NBUCKETS,hist);
}


int main(){
	cout<<"Histogram serial"<<endl;
	float *A;

	A=(float*)malloc(sizeof(float)*NVALS);

	init_arr(A);
	// print_arr(NVALS,A);
	histogram(A);

	free(A);
	return 0;
}
