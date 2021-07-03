#!/bin/bash

contador=4000000

for i in `seq 1 25`
do
	echo $contador
	./minmax $contador >> salida-minmax.dat

	contador=`expr $contador + 4000000` 
done
