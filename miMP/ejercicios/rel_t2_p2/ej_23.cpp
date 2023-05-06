/*Para obtener una lista de todos los números primos menores que un determinado número
n, se puede utilizar la Criba de Eratóstenes. Ese método consiste en hacer una lista de
todos los números desde 2 hasta n − 1. Tomamos el 2 y tachamos todos los múltiplos
de 2. Luego tomamos el siguiente número que se encuentra después de 2 y que esté sin
tachar, tachando de nuevo todos sus múltiplos. Repetimos este paso hasta que se acaben
los números. Los números que quedaron sin tachar son los que no tienen divisores (salvo
el 1 y él mismo) o sea los primos.
Escribir una función que obtenga los números primos menores que un determinado número
n utilizando el método anterior. La función tendrá como entrada un array de bool y el
número n, y marcará en el array de bool con el valor true aquellas casillas cuya posición
corresponda con un número primo (menor a n) y con el valor false las posiciones que no
correspondan con números primos. La posiciones 0 y 1 las marcaremos con true.*/


#include <iostream>
#include <string>

using namespace std;

void printArray(const bool array[], int used){
    for (int i = 0; i < used; i++){
        cout << i << " " << (array[i]? "True" : "False") << endl;
    }
}

void CribaEratostenes(bool array[], int &used, int n){
    used = n;

    for (int i = 0; i < n; i++){
        array[i] = true;
    }

    for (int i = 2; i < used; i++){
        if (array[i]){
            for (int j = i+1; j < used; j++){
                if (j % i == 0){
                    array[j] = false;
                }
            }
        }
    }
}


int main(){
    const int limit = 100;
    bool array[limit];
    int used;

    CribaEratostenes(array, used, 100);

    printArray(array, used);
}