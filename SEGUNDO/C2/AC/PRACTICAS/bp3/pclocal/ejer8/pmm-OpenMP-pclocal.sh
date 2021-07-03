#!/bin/bash

for i in {1..4}
do
	export OMP_NUM_THREADS=$i

	for j in 1 2
	do
		if(($j == 1))
		then
			./producto_matriz_secuencial 750
		fi

		if(($j == 2))
		then
			./producto_matriz_secuencial 1500
		fi
	done
done

