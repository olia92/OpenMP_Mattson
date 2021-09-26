#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

static long num_steps = 100000000;//100000000;
double step;


int main (){

	int i;
	double pi,sum=0.0;

	double start,end;

	printf("Serial pi calculation\nNumber of Steps : %d\n",num_steps);


	step = 1.0/(double) num_steps;

	start = omp_get_wtime();

	double x;

	for (i=0;i<num_steps;i+=1){
		x=(i+0.5)*step;
		sum += 4.0/(1.0+x*x);

	}

	pi=sum*step;
	end = omp_get_wtime();

	printf("pi = %lf\n",pi);
	printf("Time : %lf msec\n",(end-start)*1000);


	return 0;
}
