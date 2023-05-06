/*Como parte de un programa para imprimir el ı́ndice de un libro, se necesita una función
que imprima cada lı́nea. La función toma dos palabras almacenadas en cadenas de car-
acteres y la longitud de una lı́nea n como un entero y escribe ambas palabras en una sola
lı́nea. Ambas palabras estarán separadas por puntos de tal forma que la longitud total
de la lı́nea sea n caracteres.*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;


void printArray(const char array[], int used){
    for (int i = 0; i < used; i++){
        cout << array[i] << "";
    }
}

void readArray(char array[], int &used, int limit, char terminator = '#'){
    int i = 0;
    while (array[i-1] != terminator && i <= limit){
        cin >> array[i];
        i++;
    }
    used = i-1;
}

void printLine(const char w1[], int used1, const char w2[], int used2, int n){
    int aux = n - used1 - used2;
    printArray(w1, used1);
    for (int i = 0; i < aux; i++){
        cout << ".";
    }
    printArray(w2, used2);
    cout << endl;
}


int main(){
    char w1[] = "tortuga";
    char w2[] = "153";
    int used1 = 7, used2 = 3, n = 30;
    printLine(w1, used1, w2, used2, n);
}


