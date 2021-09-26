/*

This program will numerically compute the integral of

                  4/(1+x*x) 
				  
from 0 to 1.  The value of this integral is pi -- which 
is great since it gives us an easy way to check the answer.

The is the original sequential program.  It uses the timer
from the OpenMP runtime library

History: Written by Tim Mattson, 11/99.

*/
#include <stdio.h>
#include <omp.h>
static long num_steps = 100000000;
double step;

#define NUM_THREADS 3

#define PAD 8 //assume 64 byte L1 cache line size

int main ()
{
	  
	  double  pi=0.0, sum[NUM_THREADS][PAD],nthreads;
	  double start_time, run_time;

	  step = 1.0/(double) num_steps;

        	 
	  start_time = omp_get_wtime();
#pragma omp parallel
{
	  int i,id,nthrds;
	  double x;
	  id=omp_get_thread_num();
	  nthrds=omp_get_num_threads();
	  if(id==0) nthreads=nthrds;
	  for (i=id,sum[id][0]=0.0;i<= num_steps; i+=nthrds){
		  x = (i-0.5)*step;
		  sum[id][0] += 4.0/(1.0+x*x);
	  }

}
	for(int i=0;i<nthreads;i++) 
		pi += step * sum[i][0];

	  run_time = omp_get_wtime() - start_time;
	  printf("\n pi with %ld steps is %lf in %lf seconds\n ",num_steps,pi,run_time);

	  return 0;
}	  





