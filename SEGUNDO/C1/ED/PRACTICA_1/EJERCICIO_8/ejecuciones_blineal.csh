#!/bin/csh
@ inicio = 100
@ fin = 10100
@ incremento = 100
set ejecutable = mergesort_umbral_peq
set salida = tiempos_busqueda_umbral_peq.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
