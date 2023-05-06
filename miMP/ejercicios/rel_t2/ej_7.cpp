/*Haz un programa que lea el n´umero de elementos (como m´aximo 100) para un array
(vector-c) y un conjunto de n´umeros enteros ordenados de menor a mayor y los guarde en
un array. Luego debe pedir que se introduzca un n´umero entero y mostrar´a la posici´on
donde el n´umero entero se encuentra en el anterior array (o -1 si no est´a). El algoritmo
a seguir ser´a el de b´usqueda binaria. Este algoritmo consiste en localizar el elemento
central; si el buscado es m´as peque˜no seguimos buscando en la primera mitad, si no,
seguimos buscando en la segunda mitad. La implementaci´on m´as habitual mantiene dos
´ındices (izq y der) y usa un bucle que itera hasta que se encuentra el elemento o los
´ındices se cruzan:
El programa contendr´a las siguientes funciones:
• La funci´on main.
• La funci´on imprimirArray para mostrar en la salida est´andar el n´umero de elementos
(y un salto de l´ınea a continuaci´on) y los elementos de un array de enteros (separados
por espacios en blanco).
• La funci´on leerArray para leer de la entrada est´andar los elementos de un array.
Para ello recibe como par´ametro un array de enteros, su dimensi´on y el n´umero de
elementos finalmente le´ıdos (este ´ultimo par´ametro se pasa por referencia).
• La funci´on busquedaBinariaArray que reciba un dato entero a buscar, un array
de enteros, y dos enteros (´ındices inicial y final del array donde buscar el dato) y
devuelva la posici´on donde el n´umero entero se encuentra en el anterior array (o -1
si no est´a).*/


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

int binarySearch(const int array[], int to_search, int begin, int end){
    int lo = begin, hi = end;

    while(lo <= hi){
        int mid = (hi+lo) / 2;
        if (array[mid] > to_search){
            hi = mid - 1;
        }
        else if (array[mid] < to_search){
            lo = mid + 1;
        }
        else return mid;
    }

    return -1;
}

int main(){
    const int limit = 100;
    int array[limit];
    int used;
    readArray(array, used, limit);
    selectionSort(array, used);
    cout << "Array ordenado: ";
    printArray(array, used);
    int to_search;
    cout << "Elemento a buscar: ";
    cin >> to_search;
    int pos = binarySearch(array, to_search, 0, used-1);
    cout << "El elemento buscado esta en la posicion " << pos << endl;
}