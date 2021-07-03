#!/bin/bash
ntest=1

function Test() {
	clear
	echo ""
	echo "Test #"$ntest": "$*
	eval "$@" 
	echo ""
	echo "Pulsa RETURN para continuar"
	read c
	ntest=$[ntest + 1]
}

	BIN="../dist/Debug/GNU-Linux/`ls ../dist/Debug/GNU-Linux/`	"
	clear 
	echo "Validando " 
	echo "---------------"; echo 
	Test "$BIN -i"
	Test "$BIN < val_kmer1.dat"
	Test "$BIN -i val_seq2.kmer"
	Test "$BIN -o ejemplo.kmer < val_kmer1.dat; echo ''; echo 'Mostrando salida:'; more ejemplo.kmer"
	Test "$BIN -i val_seq3.kmer"
	Test "$BIN -i val_seq4.kmer"
	Test "$BIN -o salida.kmer -i val_seq5.kmer; echo ''; echo 'Mostrando salida:'; more salida.kmer"
	Test "$BIN -i noexiste.kmer"
	Test "$BIN -i val_seq2.kmer -o noexiste/salida.kmer"
	Test "$BIN -i val_kmer1.dat"
	Test "$BIN -i val_seq2.kmer -i val_seq2.kmer"
	Test "$BIN -i val_seq6.kmer -o salida.kmer"
	Test "$BIN -i val_seq7.kmer -o salida.kmer"



