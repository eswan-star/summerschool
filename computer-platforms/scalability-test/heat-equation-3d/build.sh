#!/bin/bash
#SBATCH --job-name=my_first_heat_eq
#SBATCH --account=project_465001194
#SBATCH --error=%x.%J.err
#SBATCH --output=%x.%J.out
#SBATCH --partition=small-g
#SBATCH --time=00:05:00
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=8
#SBATCH --gpus-per-node=8
##SBATCH --reservation=CSC_summer_school_gpu

# For the ntasks-per-node should equal the gpus-per-node
# for 16 gpus, we need two nodes

export MPICH_GPU_SUPPORT_ENABLED=1

srun heat_hip

