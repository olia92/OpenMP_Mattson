//************************************************************
//  University of Patras
//	Department of Electrical Engineering & Computer Technology
//
//	Course: Parallel Programming in AI
//	Week 05: OpenMp
//
//  Description: Simple examples  in openMP
//  	omp10.c: 
//	Author: Evangelos Dermatas
//	v0.1
/*
*********************************************************************
gcc -v:	gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1)
OS: 	Linux Ubuntu 18.04
CPU:	8-core, Intel(R) Core(TM) i7-2630QM CPU @ 2.00GHz, 3991 BogoMips
*********************************************************************
Compiling:	gcc omp10.c -o omp10 -fopenmp
Executing:	./omp10
Output in my Laptop:

Hello section 0
Number of sections 4
Hello omp parallel 1
Hello omp parallel 0
Hello omp parallel 2
H1 omp task 2
H2 omp task 0
H3 omp task 1
H4 omp task 2


$ ./omp10
Number of sections 4
Hello section 1
Hello omp parallel 1
Hello omp parallel 2
Hello omp parallel 0
H1 omp task 0
H4 omp task 0
H3 omp task 1
H2 omp task 2

$ ./omp10
Number of sections 4
Hello section 2
Hello omp parallel 2
Hello omp parallel 0
Hello omp parallel 1
H1 omp task 1
H2 omp task 0
H3 omp task 2
H4 omp task 1

*/
//************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// **************************************************************
int main(void)
{

#pragma omp parallel sections num_threads(4)
{
printf( "Number of sections %d\n", omp_get_num_threads() );

#pragma omp section
{
	printf( "Hello section %d\n", omp_get_thread_num() );
}

}

#pragma omp parallel num_threads(3)
{
	printf( "Hello omp parallel %d\n", omp_get_thread_num() );

//#pragma omp tasks
//#pragma omp single
{
    printf( "Single omp  %d\n", omp_get_thread_num() );
#pragma omp task
	printf( "H1 omp task %d\n", omp_get_thread_num() );
#pragma omp task
	printf( "H2 omp task %d\n", omp_get_thread_num() );
#pragma omp task
	printf( "H3 omp task %d\n", omp_get_thread_num() );
#pragma omp task
	printf( "H4 omp task %d\n", omp_get_thread_num() );
}
}
	return 0 ;
}
