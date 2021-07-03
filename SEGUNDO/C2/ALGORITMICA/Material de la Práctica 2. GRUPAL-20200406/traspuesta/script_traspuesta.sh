#!/bin/bash

contador=2

for i in `seq 1 15`
do
		
	./traspuesta-matriz $contador >> salida-matriz.dat

	contador=`expr $contador \* 2` 
done
