#include <stdio.h>
#include <stdlib.h>

#define NVALS   10
#define NBUCKETS 5

int sample(int val){
    return val/2;

}

void main(){
//******************
    int i=0,ival;
    int arr[NVALS]={8,3,5,7,8,2,5,9,2,3};
    int hist[NBUCKETS];
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