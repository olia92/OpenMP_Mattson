#include <iostream>
#include <omp.h>

using namespace std;

int main(){
    int num_threads;

    omp_set_dynamic(0);// turn off dynamic mode
    // if(omp_get_dynamic())
        cout<<"Dynumic "<<omp_get_dynamic()<<endl;
    omp_set_num_threads(omp_get_num_procs());
    cout<<"Procs num : "<<omp_get_num_procs()<<endl;
    cout<<"Active Level: "<<omp_get_active_level()<<endl;
    #pragma omp parallel
    {
        int id=omp_get_thread_num();
        cout<<"ID "<<id<<endl;
        cout<<"-> Active Level: "<<omp_get_active_level()<<endl;
        cout<<"Parallel : "<<omp_in_parallel()<<endl;

    #pragma omp single
        num_threads=omp_get_num_threads();
        cout<<"  Single num_threads ="<<num_threads<<", "<<omp_get_thread_num()<<endl;
    }

    return 0;
}

