#!/bin/bash

for i in `seq 1 12`
do
	echo Nº Procesadores: $i 
	srun -p ac --account ac -n1 --cpus-per-task=$i ./pmv-secuencial-filas 25000
done
