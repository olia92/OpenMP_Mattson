#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

static long num_steps = 100000000;//100000000;
double step;

#define NUM_THREADS 4


int main (){

	int nthreads;
	double pi=0.0;
	omp_set_num_threads(NUM_THREADS);

	double start,end;

	printf("Parallel pi calculation\nNumber of Steps : %d\n",num_steps);


	step = 1.0/(double) num_steps;

	start = omp_get_wtime();

#pragma omp parallel
{	
	int i,id, nthrds;
	double x,sum=0.0;

	id = omp_get_thread_num();
	nthrds = omp_get_num_threads();
	if(id==0) nthreads=nthrds;

	for (i=id;i<num_steps;i+=nthrds){
		x=(i+0.5)*step;		
		sum += 4.0/(1.0+x*x);
	}
#pragma omp critical
	pi += sum*step;
}

	end = omp_get_wtime();

	printf("Number of theads: %d\n",nthreads);
	printf("pi = %lf\n",pi);
	printf("Time : %lf msec\n",(end-start)*1000);


	return 0;
}
