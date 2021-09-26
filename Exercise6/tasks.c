#include <stdio.h>
#include <omp.h>


int main(){


    #pragma omp parallel
    {
        #pragma omp task
        foo();
        #pragma omp barrier
        #pragma omp single
        {
            #pragma omp task 
            bar();
        }
    }

    return 0;
}