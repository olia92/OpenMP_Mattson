#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

static long num_steps = 100000;//100000000;
double step;

#define PAD 8 //assume 64 byte L1 cacheline
#define NUM_THREADS 4


int main (){

	int i, nthreads;
	double pi,sum[NUM_THREADS][PAD];
	step = 1.0/(double) num_steps;
	omp_set_num_threads(NUM_THREADS);

	double start,end;
	start = omp_get_wtime();

	#pragma omp parallel
	{
		int i,id,nthrds;
		double x;
		double t;

		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();

		if(id==0) nthreads = nthrds;

		for (i=0,t=0.0;i<num_steps;i+=nthrds){
			x=(i+0.5)*step;
			//sum[id] += 4.0/(1.0+x*x);
			t+= 4.0/(1.0+x*x);
		}
		sum[id]=t;
	}

	for(i=0,pi=0.0;i<nthreads;i++) pi+=sum[i]*step;
	end = omp_get_wtime();


	printf("pi = %lf\n",pi);
	printf("Time : %lf msec\n",(end-start)*1000);


	return 0;
}
