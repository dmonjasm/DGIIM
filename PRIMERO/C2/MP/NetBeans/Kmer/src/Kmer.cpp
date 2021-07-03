/**
 * @file Kmer.cpp
 * @author MP
 */
#include <string>
#include <iostream>
#include "Kmer.h"

using namespace std;

Kmer::Kmer(){
    _kmer="____";
    _frecuencia=0;    
}

Kmer::Kmer(const std::string& c, int f){
    _kmer=c;
    _frecuencia=f;
}

string Kmer::getCadena() const{
    return _kmer;
}

int Kmer::getFrecuencia() const{
    return _frecuencia;
}

void Kmer::setCadena(const std::string& c){
    _kmer=c;
}

void Kmer::setFrecuencia(int f){
    _frecuencia=f;
}

void Kmer::readKmer(){
    string cadena;
    cin >> cadena;
    
    _kmer=cadena;
}

void Kmer::writeKmer() const{
    cout << _kmer;
}

