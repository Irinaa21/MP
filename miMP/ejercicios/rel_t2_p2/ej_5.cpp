/*Se pide construir una funci´on que tenga como entrada un array de caracteres (tipo char),
y suprima todas las secuencias de espacios en blanco de longitud mayor de uno. Por
ejemplo, si el array original es (’ ’,’a’,’h’,’ ’,’ ’,’ ’,’c’), el array resultante debe ser (’
’,’a’,’h’,’ ’,’c’). Las modificaciones se har´an sobre el mismo array de entrada y no se
podr´an usar arrays auxiliares. La implementaci´on debe ser lo m´as eficiente posible.*/

#include <iostream>
#include <string>

using namespace std;

void eraseElements(char array[], int &used, int pos, int to_erase){
    for (int i = pos+to_erase; i < used; i++){
        array[i-to_erase] = array[i];
    }
    used -= to_erase;
}

void eraseExtraSpaces(char array[], int &used){
    int i = 0;
    while (i < used){
        if (isspace(array[i])){
            int count = 0;
            i++;
            int space = i;

            while (isspace(array[space++])) count++;

            eraseElements(array, used, i, count);
        }
        else i++;
    }
}

void printArray(const char array[], int used){
    for (int i = 0; i < used; i++){
        cout << array[i];
    }
    cout << endl;
}



int main(){
    const int limit = 100;
    char array[limit] = {"Hola    que   tal   estas"};

    int used = 25;

    eraseExtraSpaces(array, used);

    printArray(array, used);
}