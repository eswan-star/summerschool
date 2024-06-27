#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
  int size, rank, len;
  char name[MPI_MAX_PROCESSOR_NAME];
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Get_processor_name(name, &len);
  printf("Hello from rank %d of %d from %s\n", rank, size, name);
  
  MPI_Finalize();
  if (rank == 0)
  {
     printf("\nRank zero here. There are %d number of processes happening right now!", size);
  }
}
