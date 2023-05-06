/*Haz un programa que lea una serie de n´umeros enteros (como m´aximo 100) y que elimine
los elementos repetidos guard´andolos en un nuevo array.
El algoritmo empleado para eliminar los elementos repetidos consistir´a en recorrer sucesivamente el array a partir de la posici´on 1, buscando si el elemento actual est´a en el subarray que comienza en la posici´on 0 y acaba en la posici´on anterior a la actual. Si es as´ı,
lo borraremos desplazando hacia la izquierda todos los elementos siguientes al elemento
actual. Como puede verse, podemos hacer uso de la funci´on busquedaSecuencialArray
que hicimos en el ejercicio anterior.
El programa contendr´a las siguientes funciones:
• La funci´on main para probar que todo funciona de forma correcta.
• La funci´on imprimirArray para mostrar en la salida est´andar el n´umero de elementos
(y un salto de l´ınea a continuaci´on) y los elementos de un array de enteros (separados
por espacios en blanco).
• La funci´on leerArray para leer de la entrada est´andar los elementos de un array.
Para ello recibe como par´ametro un array de enteros, su dimensi´on y el n´umero de
elementos finalmente le´ıdos (este ´ultimo par´ametro se pasa por referencia).
• La funci´on eliminarRepetidosArray para eliminar los elementos repetidos de un
array. Recibe el array de entrada, su n´umero de elementos ´utiles, el array de salida
y el n´umero de elementos ´utiles del array de salida (este ´ultimo por referencia).
Haz una segunda versi´on de la funci´on (eliminarRepetidosArray2) para eliminar los
elementos repetidos de forma que la eliminaci´on se haga sobre el mismo array de entrada,
sin usar un segundo array auxiliar.*/


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

int linear_search(int array[], int to_search, int begin, int end){
    int pos = -1;
    for (int i = begin; i < end && pos == -1; i++){
        if (array[i] == to_search) pos = i;
    }

    return pos;
}

void eraseElement(int array[], int &used, int pos){
    for (int i = pos; i < used-1; i++){
        array[i] = array[i+1];
    }
    used--;
}

void eraseRepeated(int array[], int &used){
    for (int i = 1; i < used; i++){
        if (linear_search(array, array[i], 0, i) != -1){
            eraseElement(array, used, i);
            i--;
        }
    }
}


int main(){
    const int limit = 100;
    int array[limit];
    int used;
    readArray(array, used, limit);

    eraseRepeated(array, used);

    cout << "Array leido: ";
    printArray(array, used);
}