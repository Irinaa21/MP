/*Haz un programa que lea el n´umero de elementos (como m´aximo 100) para un array
(vector-c) y un conjunto de n´umeros enteros y los guarde en un array y lo invierta,
mostrando el resultado. Si la secuencia introducida es 1, 100, 34, 48, 53, entonces
el resultado final mostrado debe ser 53, 48, 34, 100, 1. El programa contendr´a las
siguientes funciones:
• La funci´on main para probar que todo funciona de forma correcta.
• La funci´on imprimirArray para mostrar en la salida est´andar el n´umero de elementos
(y un salto de l´ınea a continuaci´on) y los elementos de un array de enteros (separados
por espacios en blanco).
• La funci´on leerArray para leer de la entrada est´andar los elementos de un array.
Para ello recibe como par´ametro un array de enteros, su dimensi´on y el n´umero de
elementos finalmente le´ıdos (este ´ultimo par´ametro se pasa por referencia).
• La funci´on invertirArray que reciba un array de enteros y el n´umero de elementos
´utiles del array, e invierta el array de entrada (sin usar ning´un otro array auxiliar).*/

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

void reverseArray(int array[], int used){
    for (int i = 0; i < used/2; i++){
        int aux = array[i];
        array[i] = array[used-1-i];
        array[used-1-i] = aux;
    }
}


int main(){
    const int limit = 100;
    int array[limit];
    int used;
    readArray(array, used, limit);
    reverseArray(array, used);
    cout << "Array invertido: ";
    printArray(array, used);
}