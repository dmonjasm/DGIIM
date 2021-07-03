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
	Test "$BIN -l ebola.kmer ebola.dna"
	Test "$BIN -l pez.kmer pez1.dna"
	Test "$BIN -l gusano.kmer gusano1.dna gusano2.dna"
	Test "$BIN -l humano.kmer humano1.dna humano2.dna"
	Test "$BIN -l mosca.kmer mosca1.dna mosca2.dna"
	Test "$BIN -l raton.kmer raton1.dna raton2.dna"
	

