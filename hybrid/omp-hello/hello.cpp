#include <cstdio>
#include <omp.h>
int main()
{
    printf("Hello world!\n");
#pragma omp parallel
    {
        printf("Worker reporting for dooty.\n");
    }
    return 0;
}
