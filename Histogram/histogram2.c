#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


#define NVALS   100000000
#define NBUCKETS 5

int sample(int val){
    return val/2;

}

int array_init(int *A,int N){

    for(int i=0; i<N;i++){

        A[i]=(int)(rand()%10);

    }
}

void main(){
//******************
    int i=0,ival;
    int *arr;
    int hist[NBUCKETS];

    arr=(int*)malloc(sizeof(int)*NVALS);

    array_init(arr,NVALS);
//*****************************
//#pragma omp parallel for
    for(i=0;i<NBUCKETS;i++){
        //omp_init_lock(&hist_locks[i]); 
        hist[i] =0;

    }
//#pragma omp parallel for
    for(i=0;i<NVALS;i++){
        ival = (int) sample(arr[i]);
        //omp_set_lock(&hist_locks[ival]);
        hist[ival]++;
        //omp_unset_lock(&hist_locks[ival]);
    }

   // for(i=0;i<NBUCKETS;i++)
        //omp_destroy_lock(&hist_locks[i]);

    for(i=0;i<NBUCKETS;i++)
        printf("[%d] = %d\n",i,hist[i]);


}