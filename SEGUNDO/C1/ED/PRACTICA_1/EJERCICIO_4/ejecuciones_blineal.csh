#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
set ejecutable = busqueda_burbuja_alternativa
set salida = tiempos_busqueda.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 10000` >> $salida
  @ i += $incremento
end
