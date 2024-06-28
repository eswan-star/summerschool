#include <cstdio>
#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main()
{
  int omp_rank;
  int tnum;
    printf("Hello world!\n");
#pragma omp parallel private(omp_rank)
    {
	tnum = omp_get_num_threads();    
	omp_rank = omp_get_thread_num();
	sleep(1);
        printf("Thread %d worker reporting for dooty.\n %d Thread out of %d\n", omp_rank, omp_rank, tnum);
    }
    return 0;
}
