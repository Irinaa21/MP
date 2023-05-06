/*Construir una funci´on que dada una cadena de caracteres que contiene un n´umero entero,
devuelva su correspondiente valor num´erico. Razonar sobre qu´e hacer si la cadena no
contiene un n´umero entero.*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool findNumber(const char array[], int used, int &num){
    string num_s;

    int i = 0;
    bool found = false;
    while (i < used && !found){
        if ((array[i] >= '0' && array[i] <= '9') || array[i] == '-'){
            num_s += array[i++];
            while (array[i] >= '0' && array[i] <= '9'){
                num_s += array[i++];
            }
            found = true;
        }
        else i++;
    }

    if (found){
        num = stoi(num_s);
        return true;
    }
    else return false;
}


int main(){
    char array[] = {"hola que tal 5586 oisdvoi"};

    int used = strlen(array);

    int num;

    bool positive;

    if (findNumber(array, used, num)){
        cout << num << endl;
    }
    else 
        cout << "No hay numero" << endl;
}