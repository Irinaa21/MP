/*Haz un programa que lea el numero de elementos (como maximo 100) para un array
(vector-c) y un conjunto de numeros enteros y los guarde en un array e indique cual
es el menor de todos. Debe incluirse un programa principal (main) para probar las
funciones implementadas. El programa contendra las siguientes funciones:

• La funcion main para probar que todo funciona de forma correcta.
• La funcion printArray para mostrar en la salida estandar el numero de elementos
(y un salto de lınea a continuacion) y los elementos de un array de enteros (separados
por espacios en blanco).
• La funcion readArray para leer de la entrada estandar los elementos de un array.
Para ello recibe como parametro un array de enteros, su dimension y el numero de
elementos utiles finalmente leıdos (este ultimo parametro se pasa por referencia).
• La funcion buscarMinimoArray que reciba un array de enteros, y dos enteros (ındices
inicial y final del array donde buscar el mınimo) y devuelva la posicion donde se
encuentra el mınimo elemento del subarray que comienza en la posicion inicial y
acaba en la posicion final (ambas inclusive).*/

#include <iostream>
#include <string>

using namespace std;

void printArray(const int array[], int used){
    cout << used << endl;
    for (int i = 0; i < used; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void readArray(int array[], int &used, int limit){
    cout << "Numero de elementos: ";
    cin >> used;
    if (used > limit) used = limit;

    for (int i = 0; i < used && i < limit; i++){
        cin >> array[i];
    }
}

int posMinArray(int array[], int begin, int end){
    int min = array[begin];
    int pos = begin;
    for (int i = begin+1; i <= end; i++){
        if (array[i] < min){
            min = array[i];
            pos = i;
        }
    }

    return pos;
}


int main(){
    const int limit = 100;
    int array[limit];
    int used;
    readArray(array, used, limit);
    cout << "Array leido: ";
    printArray(array, used);

    cout << "Minimo: " << array[posMinArray(array, 0, used-1)] << endl;
}