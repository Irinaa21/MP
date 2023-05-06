/*Construir una funci´on que inserte una cadena de caracteres dentro de otra cadena
en una determinada posici´on.*/

//!Esto no tiene ningun puto sentido 

#include <iostream>
#include <string>

using namespace std;

void printArray(const char array[], int used){
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
    used = i;
}

bool insert(const char input[], int used_i, char output[], int &used_o, int pos, int limit){
    if (used_i + used_o <= limit && pos <= used_o && pos >= 0){
        for (int i = used_o-1; i >= pos; i--){
            output[i+used_i] = output[i];
            used_o++;
        }
        for (int i = pos; i < pos + used_i-1; i++){
            output[i] = input[i-pos];
        }
        return true;
    }
    else return false;
}


int main(){
    const int limit = 100;
    char array[limit], input[limit];
    int used, used_i;
    
    readArray(array, used, limit);
    readArray(input, used_i, limit);

    int pos;
    cin >> pos;

    if(insert(input, used_i, array, used, pos, limit))
        printArray(array, used);
}