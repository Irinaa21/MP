/*Haz un programa que lea el n´umero de elementos (como m´aximo 100) para un array
(vector-c) y un conjunto de n´umeros enteros y los guarde en un array. Luego debe ordenar
el array con el algoritmo de ordenaci´on por inserci´on y mostrar´a el array ya ordenado
en la salida est´andar. Este algoritmo consiste en mantener ordenada una primera parte del
array e ir insertando nuevos elementos hasta que el array queda totalmente ordenado. Por
ejemplo, si tenemos p elementos ordenados, del 0 al p−1, podemos insertar el elemento
de ´ındice p en la posici´on que le corresponda de forma que ya tendremos p+1 elementos
ordenados. Si aplicamos esta idea repetidamente, al final tendremos todos ordenados.
El programa contendr´a las siguientes funciones:
• La funci´on main.
• La funci´on imprimirArray para mostrar en la salida est´andar el n´umero de elementos
(y un salto de l´ınea a continuaci´on) y los elementos de un array de enteros (separados
por espacios en blanco).
• La funci´on leerArray para leer de la entrada est´andar los elementos de un array.
Para ello recibe como par´ametro un array de enteros, su dimensi´on y el n´umero de
elementos finalmente le´ıdos (este ´ultimo par´ametro se pasa por referencia).
• La funci´on ordenarporInsercion que reciba un array de enteros y lo ordene de
menor a mayor con el m´etodo de inserci´on.*/

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

void insertionSort(int array[], int used){
    for (int i = 1; i < used; i++){
        int j = i-1;
        while (j >= 0 && array[i] < array[j]) j--;
        int aux = array[i];
        for (int k = i-1; k > j; k--){
            array[k+1] = array[k];
        }
        array[j+1] = aux;
    }
}

int main(){
    const int limit = 100;
    int array[limit];
    int used;
    readArray(array, used, limit);
    insertionSort(array, used);
    cout << "Array ordenado: ";
    printArray(array, used);
}