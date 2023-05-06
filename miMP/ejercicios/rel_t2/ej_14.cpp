/*Haz un programa que contenga una funci´on que reciba como entrada dos cadenas de
caracteres estilo C (cad y subcad) y que compruebe si la segunda (subcad) est´a presente
o no dentro de la primera (cad). Si la subcadena es encontrada, devolver´a la posici´on
donde se encuentra y, en caso contrario, devolver´a -1.*/

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
    used = i-1;
}

int isContained(const char array[], int used, const char subarray[], int subused){
    bool is_contained = false;
    int pos = -1;
    int i = 0, j = 0; 
    while (i < used && !is_contained){
        if (array[i] == subarray[j]){
            pos = i;
            i++;
            j++;
            is_contained = true;
            while (is_contained && i < used && j < subused){
                if (array[i] != subarray[j]){
                    is_contained = false;
                    j = 0;
                    i = pos + 1;
                    pos = -1;
                }
                else {
                    i++;
                    j++;
                }
            }
        }
        else i++;
    }

    return pos;
}


int main(){
    const int limit = 100;
    char array[limit], subarray[limit];
    int used, subused;

    readArray(array, used, limit);
    readArray(subarray, subused, limit);

    int pos = isContained(array, used, subarray, subused);

    cout << pos << endl;
}