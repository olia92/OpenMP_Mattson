#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

static long num_steps = 100000000;//100000000;
double step;
#define PAD 8
#define NUM_THREADS 2


int main (){

	int i,nthreads;
	double pi,sum[NUM_THREADS][PAD];
	omp_set_num_threads(NUM_THREADS);

	double start,end;

	printf("Parallel pi calculation with pad\nNumber of Steps : %d\n",num_steps);


	step = 1.0/(double) num_steps;

	start = omp_get_wtime();

#pragma omp parallel
{	
	int i,id, nthrds;
	double x;

	id = omp_get_thread_num();
	nthrds = omp_get_num_threads();
	if(id==0) nthreads=nthrds;

	for (i=id,sum[id][0]=0.0;i<num_steps;i+=nthrds){
		x=(i+0.5)*step;
		sum[id][0] += 4.0/(1.0+x*x);

	}
}
	for(i=0,pi=0.0;i<nthreads;i++) pi+=sum[i][0]*step;
	end = omp_get_wtime();

	printf("Number of theads: %d\n",nthreads);
	printf("pi = %lf\n",pi);
	printf("Time : %lf msec\n",(end-start)*1000);


	return 0;
}
