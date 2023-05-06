/*Construir una función que ordene alfabéticamente una cadena
de caracteres*/

#include <iostream>
#include <string>

using namespace std;

void printArray(const char array[], int used){
    for (int i = 0; i < used; i++){
        cout << array[i] << "";
    }
    cout << endl;
}

void readArray(char array[], int &used, int limit, char terminator = '#'){
    int i = 0;
    while (array[i-1] != terminator && i <= limit){
        cin >> array[i];
        i++;
    }
    used = i-1;
}

void swapElements(char array[], int i, int j){
    char aux = array[i];
    array[i] = array[j];
    array[j] = aux;
}

void sortAlphabet(char array[], int used){
    bool change = true;
    for (int i = 0; i < used && change; i++){
        change = false;
        for (int j = used - 1; j > i; j--){
            if (array[j] < array[j-1]){
                swapElements(array, j, j-1);
                change = true;
            }
        }
    }
}


int main(){
    const int limit = 100;
    char array[limit];
    int used;

    readArray(array, used, limit);

    sortAlphabet(array, used);

    printArray(array, used);
}