/*Haz un programa que lea un texto desde cin y que, al finalizar la entrada de datos,
muestre cu´antas veces aparece cada letra (a..z), teniendo en cuenta lo siguiente:
• La entrada de datos finaliza con el car´acter #.
• No se diferenciar´an may´usculas y min´usculas.

El programa contendr´a las siguientes funciones:
• La funci´on leerCaracteres() para leer car´acter a car´acter de la entrada est´andar
guard´andolos en array hasta que encuentre el car´acter #. Para ello recibir´a como
par´ametro un array de caracteres, su dimensi´on y el n´umero de caracteres (salida)
finalmente le´ıdos.
• La funci´on contarCaracteres() calcula la frecuencia con que aparece cada car´acter
en el array de caracteres recibido, guardando tales frecuencias en un array de enteros
que sirve como contador de cada car´acter (a..z). De esta forma, la funci´on recibir´a
como par´ametro un array de caracteres (entrada), su n´umero de elementos ´utiles y
un array de enteros (salida) donde la funci´on guardar´a la frecuencia de cada car´acter.*/

#include <iostream>
#include <string>

using namespace std;

void printArray(const char array[], int used){
    for (int i = 0; i < used; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void printArray(const int array[], int used){
    cout << used << endl;
    for (int i = 0; i < used; i++){
        cout << array[i] << " ";
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

void countCharacters(const char input[], int used, int output[]){
    for (int i = 0; i < used; i++){
        if (isalpha(input[i])){
            output[input[i] - (islower(input[i])? 'a': 'A')]++;
        }
    }
}


int main(){
    int counter[26] = {0};
    const int limit = 100;

    char array[limit];
    int used;
    readArray(array, used, limit);
    cout << used << endl;
    countCharacters(array, used, counter);

    printArray(array, used);
    printArray(counter, 26);
    
}