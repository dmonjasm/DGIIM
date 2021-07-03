#!/bin/bash

sched=$1
j=0

for i in 1 2 3
do
	if (($i == 1))
	then
		export OMP_SCHEDULE="$1"
		./pmtv-OpenMP 17280
	fi

	if (( $i == 2))
	then
 	 	export OMP_SCHEDULE="$1,1"
		./pmtv-OpenMP 17280
	fi

	if (( $i == 3))
	then 
		export OMP_SCHEDULE="$1,64"
		./pmtv-OpenMP 17280
	fi
done

