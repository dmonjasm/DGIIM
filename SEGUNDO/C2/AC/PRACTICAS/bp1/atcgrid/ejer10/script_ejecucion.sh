#!/bin/bash
#Órdenes para el sistema de colas:
#1. Asigna al trabajo un nombre
#SBATCH --job-name=helloOMP
#2. Asignar el trabajo a una cola (partición) 
#SBATCH --partition=ac 
#2. Asignar el trabajo a un account 
#SBATCH --account=ac

#Obtener información de las variables del entorno del sistema de colas:
srun -p ac --account ac -n1 --cpus-per-task=12 echo "Id. usuario del trabajo: $SLURM_JOB_USER"
srun -p ac --account ac -n1 --cpus-per-task=12 echo "Id. del trabajo: $SLURM_JOBID"
srun -p ac --account ac -n1 --cpus-per-task=12 echo "Nombre del trabajo especificado por usuario: $SLURM_JOB_NAME"
srun -p ac --account ac -n1 --cpus-per-task=12 echo "Directorio de trabajo (en el que se ejecuta el script): $SLURM_SUBMIT_DIR"
srun -p ac --account ac -n1 --cpus-per-task=12 echo "Cola: $SLURM_JOB_PARTITION"
srun -p ac --account ac -n1 --cpus-per-task=12 echo "Nodo que ejecuta este trabajo:$SLURM_SUBMIT_HOST"
srun -p ac --account ac -n1 --cpus-per-task=12 echo "Nº de nodos asignados al trabajo: $SLURM_JOB_NUM_NODES"
srun -p ac --account ac -n1 --cpus-per-task=12 echo "Nodos asignados al trabajo: $SLURM_JOB_NODELIST"
srun -p ac --account ac -n1 --cpus-per-task=12 echo "CPUs por nodo: $SLURM_JOB_CPUS_PER_NODE"
#Instrucciones del script para ejecutar código:
 
for ((P=16384;P<=67108864;P=P*2))
do
   srun -p ac --account ac -n1 --cpus-per-task=12 ./listado_paralelo $P
done
