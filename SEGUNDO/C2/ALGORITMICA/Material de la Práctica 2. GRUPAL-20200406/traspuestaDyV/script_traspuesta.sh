#!/bin/bash

contador=2

for i in `seq 1 15`
do
		
	./traspuesta-matriz_DyV $contador >> salida-matrizDyV.dat

	contador=`expr $contador \* 2` 
done
