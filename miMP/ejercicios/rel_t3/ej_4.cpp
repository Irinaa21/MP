/*Declare una variable v como un array de 1000 enteros. Escriba un trozo de código que recorra el array y
modique todos los enteros negativos cambiándolos de signo. No se permite usar el operador [], es decir, el
recorrido se efectuará usando aritmética de punteros y el bucle se controlará mediante un contador entero.*/


#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>

using namespace std;


void generarArray(int *array, int to_use){
    srand(time(NULL));

    for (int i = 0; i < to_use; i++){
        *(array+i) = rand();
    }
}
void printArray(const int *array, int used){
    cout << used << endl;
    for (int i = 0; i < used; i++){
        cout << *(array+i) << " ";
    }
    cout << endl;
}

void valorAbsoluto(int *array, int used){
    for (int i = 0; i < used; i++){
        *(array+i) = abs(*(array+i));
    }
}

int main(){
    const int dim = 1000;
    int array[dim];

    generarArray(array, dim);
    printArray(array, dim);
    valorAbsoluto(array, dim);
    printArray(array, dim);

    return 0;
}