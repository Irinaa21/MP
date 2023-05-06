/*Construir una función que reciba una cadena de caracteres y compruebe si contiene un
número de identificación fiscal (NIF) o número de identidad de extranjero (NIE) válido.
La función debe devolver el tipo de documento y si es o no válido. Decidir cómo se
devuelve esta información.
El NIF se forma con 8 dı́gitos seguidos de una letra (dı́gito de control). El proced-
imiento empleado para el cálculo del NIF consiste en hallar el resto de la división por
23 del número formado por los 8 dı́gitos. El resto resultante (comprendido entre 0 y
22) se corresponde con la letra en dicha posición (comenzando por 0) de la secuencia
TRWAGMYFPDXBNJZSQVHLCKE. El NIE sigue el mismo procedimiento pero su sustituyendo
el primer dı́gito del NIF por la letra X.*/


#include <iostream>
#include <string>
#include <cstring>

using namespace std;

enum class Tipos {ninguno, nie, nif};
const string LetrasNIE = "TRWAGMYFPDXBNJZSQVHLCKE";
const int limit = 100;

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
    array[i] = '\0';
    used = i-1;
}

bool isNum(const char s[]){
    bool is_num = true;
    for (int i = 0; i < strlen(s) && is_num; i++){
        if (s[i] < '0' || s[i] > '9'){
            is_num = false;
        }
    }

    return is_num;
}

void substr(const char input[], int used, char output[], int pos, int lon){
    int i,j;
    for (i = 0, j = pos; i < lon; i++, j++){
        output[i] = input[j];
    }
    output[i+1] = '\0';
}

Tipos nie_nif(const char s[]){
    Tipos nie_nif;

    if (strlen(s) != 9){
        nie_nif = Tipos::ninguno;
    }
    else if (s[0] == 'X'){
        char aux[8];
        substr(s, strlen(s), aux, 1, 7);
        if (!isNum(aux)){
            nie_nif = Tipos::ninguno;
        }
        else{
            string num = aux;
            if (s[8] != LetrasNIE[stoi(num) % 23]){
                nie_nif = Tipos::ninguno;
            }
            else
                nie_nif = Tipos::nif;
        }
    }
    else{
        char aux[9];
        substr(s, strlen(s), aux, 0, 8);
        if (!isNum(aux)){
            nie_nif = Tipos::ninguno;
        }
        else{
            string num = aux;
            if (s[8] != LetrasNIE[stoi(num) % 23]){
                nie_nif = Tipos::ninguno;
            }
            else
                nie_nif = Tipos::nif;
        }
    }

    return nie_nif;
}

