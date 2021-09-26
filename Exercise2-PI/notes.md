## Compile 

'gcc -o pi_omp pi_omp.c -fopenmp'
'time ./pi_omp'

##### Output:

'''

Num threads: 4
pi = 3.141623
Time : 2.112967 msec

real	0m0,004s
user	0m0,010s
sys	0m0,001s

'''