#!/bin/bash

echo "¿Quieres generar un pdf del proyecto? Responde Si(s) o No(n)"
echo "ADVERTENCIA: SE REQUIERE TENER INSTALADO LATEX EN TU ORDENADOR"

while :
do
	read respuesta
	case $respuesta in
		s)
			cd ./doc/doxy/latex; make; cd ..; mv ./latex/*.pdf ./
			break
			;;
		n)
			echo "Vale. No se generará ningún pdf"
			break
			;;
		*)
			echo "No se ha introducido ninguna respuesta correcta"
			echo "Para generar el pdf pulse s. Para no generarlo pulse n"
			;;
	esac
done



