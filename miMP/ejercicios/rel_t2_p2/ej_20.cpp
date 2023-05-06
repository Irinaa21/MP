/*Dado un array X de n elementos reales donde n es impar, diseñar una función para
calcular la mediana de ese array. La mediana se define como el valor mayor que la mitad
de los números y menor que la otra mitad.*/


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

    cout << array[used/2] << endl;
}