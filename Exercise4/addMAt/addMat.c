//************************************************************
//  University of Patras
//	Department of Electrical Engineering & Computer Technology
//
//	Course: Parallel Programming in AI
//	Week 03: Code Optimization & vector processing & openMP
//
//  Description: Arithmetic operations of Large two dimensional Matrices
//  	addmatOrg02omp.c:
//	Author: Evangelos Dermatas
//	v0.1
/*
*********************************************************************
gcc -v:	gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1)
OS: 	Linux Ubuntu 18.04
CPU:	8-core, Intel(R) Core(TM) i7-2630QM CPU @ 2.00GHz, 3991 BogoMips
*********************************************************************
Compiling:	gcc addmatOrg02omp.c -o addmatOrg02omp -fopt-info-vec-optimized
Executing:	time ./addmatOrg02omp
Output in my Laptop:

innerProdMat  207115863

real	0m0.177s
user	0m0.922s
sys	0m0.004s
*/

// *******************************************************************


//************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// **************************************************************
// Matrices Dimension
#define N	1000

// **************************************************************
int A[N][N] ;
int B[N][N] ;
int C[N][N] ;
int T[N][N] ;


// ***************************************************************************
//    Set random values to the elements of a two dimensional matrix a[N][N]
// 		in the range [-50,49]
// ***************************************************************************
void setValMat( int a[N][N] )
{
	int i, j ;
	for( i = 0 ; i < N ; i++ )
		for( j = 0 ; j < N ; j++ )
		    a[i][j] = (rand() % 100) - 50 ;
}

// ***************************************************************************
//    Add matrix a to b into c
// ***************************************************************************
void addMat( int a[N][N], int b[N][N], int c[N][N] )
{



   	for( int i = 0 ; i < N ; i++ )

		for( int j = 0 ; j < N ; j++ )
	    	c[i][j] = a[i][j] + b[i][j] ;
}

// ***************************************************************************
//    Compute the inner product of a and b
// ***************************************************************************
int innerProdMat( int a[N][N], int b[N][N] )
{
	int i, j, sum = 0 ;


	for( i = 0 ; i < N ; i++ ) {

	sum = 0 ;


	    for( j = 0 ; j < N ; j++ )
		    sum += a[i][j]*b[i][j] ;
	}
	return sum ;
}

// ***************************************************************************
//    Compute Transpose of a into  b
// ***************************************************************************
void tranMat( int a[N][N], int b[N][N] )
{


   	for( int i = 0 ; i < N ; i++ )
		for( int j = 0 ; j < N ; j++ )
			b[i][j] = a[j][i] ;
}

// ***************************************************************************
//    Compute in c the product of a and b
// ***************************************************************************
void mulMat01( int a[N][N], int b[N][N], int c[N][N] )
{
	int i, j, k, s ;


   	for( i = 0 ; i < N ; i++ )
		for( j = 0 ; j < N ; j++ ) {


		s = 0 ;


	        for( k = 0 ; k < N ; k++ )
		        s += a[i][k] * b[j][k] ;
		c[i][j] = s ;
	   }
}


// **************************************************************
int main(void)
{
int res ;
	setValMat( A ) ;
	setValMat( B ) ;
	addMat( A, B, C ) ;
        tranMat( B, T) ;

	mulMat01( C, T, A ) ;
	res = innerProdMat( A, B ) ;
	printf( "innerProdMat  %d\n", res ) ;

	return 0 ;
}
