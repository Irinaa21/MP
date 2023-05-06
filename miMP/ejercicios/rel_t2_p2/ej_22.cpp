/*Escribir un programa que calcule y muestre por pantalla los 20 primeros términos de la
sucesión de Fibonacci de orden 4. El programa debe usar obligatoriamente una función
que calcule y almacene en un array los k primeros términos de la sucesión de Fibonacci
de orden n. Obviamente, k y n serán parámetros del módulo.
La sucesión de Fibonacci de orden n es una secuencia de números en la que los dos
primeros son el 0 y el 1. A partir del tercero, los elementos se calculan como la suma de
los n anteriores, si ya hay n elementos disponibles, o la suma de todos los anteriores si
hay menos de n elementos disponibles.*/

#include <iostream>
#include <string>

using namespace std;

void Fibonacci(int array[], int &used, int k, int n){
    used = k;
    array[0] = 0;
    array[1] = 1;

    for (int i = 2; i < k; i++){
        array[i] = 0;
        for (int j = max(0,i-n); j < i; j++){
            array[i] += array[j];
        }
    }
}


void printArray(const int array[], int used){
    cout << used << endl;
    for (int i = 0; i < used; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}


int main(){
    const int limit = 100;
    int array[limit];
    int used;

    Fibonacci(array, used, 20, 4);

    printArray(array, used);
}