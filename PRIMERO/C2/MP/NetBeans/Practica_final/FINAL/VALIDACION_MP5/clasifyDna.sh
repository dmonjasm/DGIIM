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
	Test "$BIN -c unknown1.dna gusano.kmer humano.kmer raton.kmer mosca.kmer pez.kmer ebola.kmer"
	Test "$BIN -c unknown2.dna gusano.kmer humano.kmer raton.kmer mosca.kmer pez.kmer ebola.kmer"
	Test "$BIN -c unknown3.dna gusano.kmer humano.kmer raton.kmer mosca.kmer pez.kmer ebola.kmer"
	Test "$BIN -c unknown4.dna gusano.kmer humano.kmer raton.kmer mosca.kmer pez.kmer ebola.kmer"

