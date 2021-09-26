#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void foo(int id){
    printf("foo: task %d\n",id);
}
void bar(int id){
    printf("bar: task %d\n",id);
}

int main(){
    int id;

#pragma omp parallel
{
    // printf("Threads: %d\n",omp_get_thread_num());
    id=omp_get_thread_num();
    #pragma omp task
    foo(id);
    #pragma omp barrier
    #pragma omp single
    {
        #pragma omp task
        bar(id);
    }
}

    return 0;
}