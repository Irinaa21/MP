/* 

Haz un programa que lea de la entrada estandar el numero de elementos que tendra un
array de enteros, y dos enteros para el rango (minimo, maximo) de posibles valores que
tomaran los elementos del array. El programa rellenara el array con numeros aleatorios
enteros en el rango proporcionado, y posteriormente lo mostrara en la salida estandar. El
programa contendra las siguientes funciones:

• La funcion main para probar que todo funciona de forma correcta.

• La funcion imprimirArray para mostrar en la salida estandar el numero de elementos
(y un salto de lınea a continuacion) y los elementos de un array de enteros (separados
por espacios en blanco).

• La funcion generarArray que recibe un array de enteros, el numero de elementos a
usar y un rango de valores (mınimo, maximo) y lo rellena con numeros aleatorios en
el rango proporcionado.

*/

#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>

using namespace std;

void imprimirArray(const int array[], int used){
    cout << used << endl;
    for (int i = 0; i < used; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void generarArray(int array[], int to_use, int min, int max){
    srand(time(NULL));

    for (int i = 0; i < to_use; i++){
        array[i] = min + rand() % ((max+1) - min);
    }
}

int main(){
    const int limit = 100;
    int array[limit];

    int num, min, max;

    cout << "Numero de elementos: ";
    cin >> num;
    cout << "Minimo: ";
    cin >> min;
    cout << "Maximo: ";
    cin >> max;

    if (num > limit){
        throw std::out_of_range("Out of range");
    }

    generarArray(array, num, min, max);
    imprimirArray(array, num);

    return 0;
}