/*Haz un programa que obtenga la mayor secuencia mon´otona creciente de un array
de enteros le´ıdo de la entrada est´andar, guard´andola en otro array que se mostrar´a en la
salida est´andar.*/

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

void copyArray(const int input[], int used_i, int output[], int &used_o){
    for (int i = 0; i < used_i; i++){
        output[i] = input[i];
    }
    used_o = used_i;
}

void greatestMonotGrowSec(const int input[], int used_i, int output[], int &used_o){
    int aux[used_i];
    int used_aux = 0;
    if (used_i != 0){
        aux[used_aux++] = input[0];
    }

    for (int i = 1; i < used_i; i++){
        if (input[i] > aux[used_aux-1]){
            aux[used_aux++] = input[i];
        }
        else if (used_aux > used_o){
            copyArray(aux, used_aux, output, used_o);
            aux[0] = input[i];
            used_aux = 1;
        }
        else{
            aux[0] = input[i];
            used_aux = 1;
        }
    }
}


int main(){
    const int limit = 100;
    int array[limit];
    int used;
    readArray(array, used, limit);

    int sec[limit];
    int used_s;

    greatestMonotGrowSec(array, used, sec, used_s);

    printArray(sec, used_s);

}