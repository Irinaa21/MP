/*Haz un programa que lea el n´umero de elementos (como m´aximo 100) para un array
(vector-c) y un conjunto de n´umeros enteros y los guarde en un array. Luego debe
ordenar el array con el algoritmo de ordenaci´on por selecci´on y mostrar´a el array
ya ordenado en la salida est´andar. Este algoritmo consiste en recorrer el array a partir
de la posici´on 0, repitiendo sucesivamente los siguientes pasos:
(a) Buscar el elemento m´as peque˜no del array (desde posici´on actual hasta el final).
(b) Intercambiar el elemento m´as peque˜no con el elemento de la posici´on actual.
F´ıjate, que puedes usar el m´etodo buscarMinimoArray implementado en un ejercicio
anterior para hacer el paso a).
El programa contendr´a las siguientes funciones:
• La funci´on main.
• La funci´on imprimirArray para mostrar en la salida est´andar el n´umero de elementos
(y un salto de l´ınea a continuaci´on) y los elementos de un array de enteros (separados
por espacios en blanco).
• La funci´on leerArray para leer de la entrada est´andar los elementos de un array.
Para ello recibe como par´ametro un array de enteros, su dimensi´on y el n´umero de
elementos finalmente le´ıdos (este ´ultimo par´ametro se pasa por referencia)
• La funci´on buscarMinimoArray que reciba un array de enteros, y dos enteros (´ındices
inicial y final del array donde buscar el m´ınimo) y devuelva la posici´on donde se
encuentra el m´ınimo elemento del subarray que comienza en la posici´on inicial y
acaba en la posici´on final (ambas inclusive).
• La funci´on ordenarporSeleccion que reciba un array de enteros y lo ordene de
menor a mayor con el m´etodo de selecci´on.*/

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

void selectionSort(int array[], int used){
    for (int i = 0; i < used; i++){
        int j = posMinArray(array, i, used-1);
        int aux = array[i];
        array[i] = array[j];
        array[j] = aux;
    }
}

int main(){
    const int limit = 100;
    int array[limit];
    int used;
    readArray(array, used, limit);
    selectionSort(array, used);
    cout << "Array ordenado: ";
    printArray(array, used);
}