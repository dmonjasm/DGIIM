#!/bin/bash
export TERM=xterm-256color
ntest=1

function Test() {
	echo ""
	echo "Test #"$ntest": "$*
	eval "$@" 
	echo ""
	echo "Pulsa RETURN para continuar"
	read c
	ntest=$[ntest + 1]
}

	BIN="valgrind --leak-check=full ../dist/Debug/GNU-Linux/`ls ../dist/Debug/GNU-Linux/`	"
	echo "Validando " 
	echo "---------------"; echo 
	
	rm *.kmer
	#GESTION DE FALLOS DEL PROGRAMA
	Test "$BIN -i"
	Test "$BIN -l gusano.kmer"
	Test "$BIN -c gusano1.dna"
	Test "$BIN gusano1.dna -l"
	Test "$BIN unknown.dna -c gusano.kmer ebola.kmer humano.kmer raton.kmer pez.kmer"
	Test "$BIN -l ebola.kmer noexiste.dna"
	Test "$BIN -l ebola.kmer noexiste.dna noexiste2.dna noexiste3.dna"
	rm ebola.kmer
	
	#CREACION DE DICCIONARIOS .KMER
	Test "$BIN -l gusano.kmer gusano1.dna"
	Test "$BIN -l gusano.kmer gusano2.dna"
	rm gusano.kmer

	Test "$BIN -l gusano.kmer gusano1.dna gusano2.dna"
	
	#CREACION DE TODOS LOS DICCIONARIOS (CON ALGUNOS FICHEROS FANTASMA)
	Test "$BIN -l ebola.kmer ebola.dna noexiste.dna noexiste2.dna"
	Test "$BIN -l pez.kmer noexiste.dna pez1.dna noexiste2.dna noexiste3.dna"
	Test "$BIN -l raton.kmer raton1.dna raton2.kmer raton2.dna"
	Test "$BIN -l mosca.kmer mosca1.dna mosca2.dna"
	Test "$BIN -l humano.kmer humano1.dna humano2.dna"

	#TEST DE CLASIFICACION
	Test "$BIN -c unknown1.dna gusano.kmer humano.kmer raton.kmer mosca.kmer pez.kmer ebola.kmer"
	Test "$BIN -c unknown2.dna gusano.kmer humano.kmer raton.kmer mosca.kmer pez.kmer ebola.kmer"
	Test "$BIN -c unknown3.dna gusano.kmer humano.kmer raton.kmer mosca.kmer pez.kmer ebola.kmer"
	Test "$BIN -c unknown4.dna gusano.kmer humano.kmer raton.kmer mosca.kmer pez.kmer ebola.kmer"
	Test "$BIN -c unknown1.dna noexiste.kmer noexiste2.kmer noexiste3.kmer noexiste4.kmer noexiste5.kmer"
	Test "$BIN -c unknown1.dna noexiste.kmer noexiste2.kmer noexiste3.kmer mosca.kmer gusano.kmer"
	Test "$BIN -c unknown1.dna ebola.dna mosca1.dna raton.dna humano.dna gusano.dna"


