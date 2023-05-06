/*Realizar una función que construya un array conteniendo todos los elementos menores a
100 del conjunto C definido a continuación:
(a) El número 1 pertenece a C.
(b) Si x pertenece a C, entonces 2x + 1 y 3x + 1 también pertenecen a C.
(c) Ningún otro número está en C.
C tendrá el siguiente aspecto: {1, 3, 4, 7, 9, 10, · · · }. El array resultado debe aparecer
ordenado en orden creciente.*/

#include <iostream>
#include <string>

using namespace std;

void printArray(int *array, int used){
    cout << used << endl;
    for (int i = 0; i < used; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

bool isInArray(int *array, int used, int to_search){
    for (int i = 0; i < used; i++){
        if (array[i] == to_search){
            return true;
        }
    }

    return false;
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

void selectionSort(int *array, int used){
    for (int i = 0; i < used; i++){
        int j = posMinArray(array, i, used-1);
        int aux = array[i];
        array[i] = array[j];
        array[j] = aux;
    }
}

void fillArray(int *array, int &used, int tope){
    array[0] = 1;
    used = 1;
    
    for (int i = 0; i < used; i++){
        int aux = 2*array[i]+1;
        if(aux < tope && !isInArray(array, used, aux)){
            array[used++] = aux;
        }
        aux = 3*array[i]+1;
        if(aux < tope && !isInArray(array, used, aux)){
            array[used++] = aux;
        }
    }

    selectionSort(array, used);
}



int main(){
    const int tope = 100;
    int *array = new int[tope];
    int used;

    fillArray(array, used, tope);
    //selectionSort(array, used);
    printArray(array, used);
}