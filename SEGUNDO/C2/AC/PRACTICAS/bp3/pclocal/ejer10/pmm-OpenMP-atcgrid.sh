#!/bin/bash

for i in {1..4}
do
	export OMP_NUM_THREADS=$i

	for j in 1 2
	do
		if(($j == 1))
		then
			srun -n1 -p ac --account ac --cpus-per-task=$i --hint=nomultithread ./producto_matriz_paralelo 750
		fi

		if(($j == 2))
		then
			srun -n1 -p ac --account ac --cpus-per-task=$i --hint=nomultithread ./producto_matriz_paralelo 1500
		fi
	done
done
