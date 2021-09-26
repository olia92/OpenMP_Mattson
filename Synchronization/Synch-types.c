//Barrier

#pragma omp parallel
	{
		int id=omp_get_thread_num();
		A[id] = big_cal1(id);
	#pragma omp barrier

		B[id] = big_calc2(id,A);

	}
//-------------------------------------------------

//Mutual exclusion example
float res;

#pragma omp parallel 
{
	float B; int i,id,nthrds;
	id = omp_get_thread_num();
	nthrds = omp_get_num_threads();
	for(i=id;i<niters; i+=nthrds){
		B = big_job(i);
#pragma omp critical
	res += consume(B);
	}
}

//-------------------------------------------------

//Atomic

#pragma omp parallel
{
	double tmp,B;
	B = DOIT();
	tmp = big_ugly(B);
#pragma omp atomic	
	X += tmp;

}

//-------------------------------------------------