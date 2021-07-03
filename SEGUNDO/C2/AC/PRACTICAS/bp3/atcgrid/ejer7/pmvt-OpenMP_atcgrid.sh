#!/bin/bash

sched=$1
j=0

for i in 1 2 3
do
	if (($i == 1))
	then
		export OMP_SCHEDULE="$1"
		srun -n1 -p ac --account ac --cpus-per-task=12 --hint=nomultithread ./pmtv-OpenMP 17280
	fi

	if (( $i == 2))
	then
 	 	export OMP_SCHEDULE="$1,1"
		srun -n1 -p ac --account ac --cpus-per-task=12 --hint=nomultithread ./pmtv-OpenMP 17280
	fi

	if (( $i == 3))
	then 
		export OMP_SCHEDULE="$1,64"
		srun -n1 -p ac --account ac --cpus-per-task=12 --hint=nomultithread ./pmtv-OpenMP 17280
	fi
done

