#include <cstdio>
#include <cmath>
#include <mpi.h>

constexpr int n = 10000;
int rank, ntasks;
MPI_Status status;

int main(int argc, char** argv){

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  double rankzero = 0.0, rankone = 0.0;

  if (rank == 0){
  	printf("Computing approximation to pi with first rank up to N=%d\n", n/2);

  	int istart = 1;
  	int istop = n/2;

  	for (int i=istart; i <= istop; i++) {
    		double x = (i - 0.5) / n;
    		rankzero += 1.0 / (1.0 + x*x);
  	}
  
 	MPI_Recv(&rankone, 1, MPI_DOUBLE, 1, 52, MPI_COMM_WORLD, &status);

	double pi = rankzero + rankone;
	pi *= 4.0/n;
        printf("Approximate pi=%18.16f (exact pi=%10.8f)\n", pi, M_PI);
	
  }

  if (rank == 1){
 	printf("Computing approximation to pi with second rank up N=%d\n", n);

	int istart = (n/2) + 1;
        int istop = n;

        for (int i=istart; i <= istop; i++) {
                double x = (i - 0.5) / n;
                rankone += 1.0 / (1.0 + x*x);
        }

  	MPI_Send(&rankone, 1, MPI_DOUBLE, 0, 52, MPI_COMM_WORLD);
  }
  
  MPI_Finalize();	

  }
