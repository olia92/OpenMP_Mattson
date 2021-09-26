#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

static long num_steps = 100000;
double step;


int main (){

	int i;
	double x,pi,sum=0.0;

	double start,end;

	step = 1.0/(double) num_steps;
	

	start = omp_get_wtime();

	#pragma omp parallel
	{
		int t=omp_get_thread_num();
		printf("Thread : %d\n",t);

	for (i=0;i<num_steps;i++){
		x=(i+0.5)*step;
		sum = sum + 4.0/(1.0+x*x);
	}

	printf("Sum [%d] = %lf\n",t,sum);
	}

	end = omp_get_wtime();

	pi=step*sum;

	printf("pi = %lf\n",pi);
	printf("Time : %lf msec\n",(end-start)*1000);


	return 0;
}
