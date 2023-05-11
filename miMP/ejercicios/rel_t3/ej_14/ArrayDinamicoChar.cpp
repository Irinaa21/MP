#include <fstream>
#include <cstdlib>
#include <iostream>

#include "ArrayDinamicoChar.h"
using namespace std;

void inicializar(char *&p, int n){
    if (n > 0)
        p = new char[n];
    else p = 0;
}

void liberar(char *p, int &n){
    delete[] p;
    n = 0;
}

void mostrar(ostream &flujo, char *array, int n){
    for (int i = 0; i < n; i++){
        flujo << *(array+i) << " ";
    }
}

void redimensionar(char *&array, int &n, int aumento){
    if (n + aumento > 0){
        char *aux;
        inicializar(aux, n+aumento);
    
        for (int i = 0; i < n && i < n+aumento; i++){
            *(aux+i) = *(array+i);
        }

        delete[] array;
        array = aux;
        n += aumento;
    }
}

void aniadir(char *&array, int &n, char a){
    redimensionar(array, n, 1);
    array[n-1] = a;
}

void leer(istream& flujo, char* &array, int& nchar){
    char caracter;
    liberar(array, nchar);
    while(flujo.get(caracter)){
        aniadir(array, nchar, caracter);
    }
}