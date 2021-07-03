#!/bin/bash
#SBATCH --job-name=helloOMP2
#SBATCH --partition=ac
#SBATCH --account=ac

echo "Id. usuario del trabajo: $SLURM_JOB_USER"
echo "Id. del trabajo: $SLURM_JOBID"
echo "Nombre del trabajo especificado por el usuario: $SLURM_JOB_NAME"
echo "Directorio trabajo (en el que se ejecuta el script): $SLURM_SUBMIT_DIR"
echo "Cola: $SLURM_JOB_PARTITION"
echo "Nodo que ejecuta este trabajo: $SLURM_SUBMIT_HOST"
echo "Nº de nodos asignados al trabajo: $SLURM_JOB_NUM_NODES"
echo "Nodos asignados al trabajo: $SLURM_JOB_NODELIST"
echo "CPUs por nodo: $SLURM_JOB_SPUS_PER_NODE"
echo -e "\n 1. Ejecución helloOMP una vez sin cambiar nº de threads (valor por defector):\n"
./HelloOMP2
echo -e "\n 2. Ejecución helloOMP varias veces con distinto nº de threads: \n"
for((P=12; P>0;P=P/2))
do
	export OMP_NUM_THREADS=$P
	echo -e "\n - Para $P threads:"
	./HelloOMP2
done
