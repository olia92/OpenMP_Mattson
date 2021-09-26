#include <stdio.h>
#include <omp.h>


int main(int argc, char **argv)
{
    const int NITEMS=20;
    int array[NITEMS];


    for (int i=0; i<NITEMS; i++)



     for (int i=0; i<NITEMS; i++) {

        int item = (i * 7) % NITEMS;


        array[item] = item;    // only one thread in here at a time; others block at set_lock()

    }

    for (int i=0; i<NITEMS; i++)
        printf("%3d ", array[i]);
    printf("\n");

    //for (int i=0; i<NITEMS; i++)



    return 0;
}