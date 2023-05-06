/*Dadas dos cadenas de caracteres, construir una función en C++ que devuelva las veces que
aparece la segunda cadena dentro de la primera. Reflexionar sobre qué deberı́a devolver
la función anterior, si las dos cadenas de entrada son aaaaa y aaa*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void readArray(char array[], int &used, int limit, char terminator = '#'){
    int i = 0;
    while (array[i-1] != terminator && i <= limit){
        cin >> array[i];
        i++;
    }
    used = i-1;
}

int numAppearances(const char input[], int used_i, const char to_search[], int used_o){
    int count = 0;
    for (int i = 0; i <= used_i - used_o; i++){
        if (input[i] == to_search[0]){
            int j = 1;
            bool is_ok = true;
            while(j < used_o && is_ok){
                if (input[i+j] != to_search[j]){
                    is_ok = false;
                }
                else j++;
            }
            if (j == used_o && is_ok) count++; 
        }
    }

    return count;
}

int main(){
    char input[] = "aaaaa";
    char to_search[] = "aaa";

    int num = numAppearances(input, 5, to_search, 3);

    cout << num << endl;
}