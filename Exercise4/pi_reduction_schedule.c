
#include <stdio.h>
#include <omp.h>
static long num_steps = 100000000;
double step;

#define NUM_THREADS 2

int main ()
{
	  //int i;
	  double  pi, sum = 0.0;
	  double start_time, run_time;

	  omp_set_num_threads(NUM_THREADS);

	  step = 1.0/(double) num_steps;

        	 
	  start_time = omp_get_wtime();

#pragma omp parallel 
{
	double x;
#pragma omp for reduction(+:sum) schedule(static,100)
	  for (int i=1;i<= num_steps; i++){
		  x = (i-0.5)*step;
		  sum = sum + 4.0/(1.0+x*x);
	  }
}
	  pi = step * sum;
	  run_time = omp_get_wtime() - start_time;
	  printf("\n pi with %ld steps is %lf in %lf seconds\n ",num_steps,pi,run_time);
}	  





