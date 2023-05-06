/*Escribid un programa que rellene dos arrays a y b con enteros, 
obtenidos de acuerdo a la siguiente recurrencia:
a0 = b0 = 1
an = bn−1
bn = an−1 + 2bn−1
El programa debe generar una tabla en la que cada fila tendr´a 
la siguiente informaci´on:
k ak bk ak/bk
Haz una conjetura sobre el valor de lim n−>∞ (an/bn)
El c´odigo resultante debe estar modularizado, incluyendo funciones 
auxiliares para todas las tareas que se consideren oportunas*/

// Ejecutando el codigo podemos ver que ese esa sucesion converge a sqrt(2) - 1

#include <iostream>
#include <string>

using namespace std;


void fillArrays(int a[], int b[], int n){
    a[0] = b[0] = 1;

    for (int i = 1; i <= n; i++){
        a[i] = b[i-1];
        b[i] = a[i-1] + 2*b[i-1];
    }
}

void printTable(const int a[], const int b[], int n){
    for (int i = 0; i < n; i++){
        cout << i << " " << a[i] << " " << b[i] << " " << (double)a[i]/b[i] << endl;
    }
}

int main(){
    const int n = 20;

    int a[n], b[n];

    fillArrays(a, b, n);

    printTable(a, b, n);
}