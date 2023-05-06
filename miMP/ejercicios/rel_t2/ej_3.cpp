/*Haz un programa que lea el n´umero de elementos (como m´aximo 100) para un array
(vector-c) y un conjunto de n´umeros enteros y los guarde en un array. Luego debe pedir
que se introduzca un n´umero entero y mostrar´a la posici´on donde el n´umero entero se
encuentra en el anterior array (o -1 si no est´a). El algoritmo consiste en una b´usqueda
secuencial. El programa contendr´a las siguientes funciones:
• La funci´on main para probar que todo funciona de forma correcta.
• La funci´on imprimirArray para mostrar en la salida est´andar el n´umero de elementos
(y un salto de l´ınea a continuaci´on) y los elementos de un array de enteros (separados
por espacios en blanco).
• La funci´on leerArray para leer de la entrada est´andar los elementos de un array.
Para ello recibe como par´ametro un array de enteros, su dimensi´on y el n´umero de
elementos finalmente le´ıdos (este ´ultimo par´ametro se pasa por referencia).
• La funci´on busquedaSecuencialArray que reciba un dato entero a buscar, un array
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

int linear_search(int array[], int to_search, int begin, int end){
    int pos = -1;
    for (int i = begin; i < end && pos == -1; i++){
        if (array[i] == to_search) pos = i;
    }

    return pos;
}

int main(){
    const int limit = 100;
    int array[limit];
    int used;
    readArray(array, used, limit);

    int to_search;
    cout << "Elemento a buscar: ";
    cin >> to_search;

    cout << "Array leido: ";
    printArray(array, used);

    int pos_searched = linear_search(array, to_search, 0, used);

    if (pos_searched == -1){
        cout << "El elemento buscado no esta en la lista" << endl;
    }
    else {
        cout << "El elemento buscado esta en la posicion " << pos_searched << " del array" << endl;
    }
}