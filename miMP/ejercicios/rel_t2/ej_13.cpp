/*Haz un programa que contenga una funci´on que compruebe si una cadena (estilo C) es
o no un pal´ındromo, es decir, que se lee igual de izquierda a derecha que de derecha a
izquierda sin tener en cuenta los espacios. Por ejemplo, anilina ser´ıa un pal´ındromo. La
funci´on para ver si la cadena es un pal´ındromo, se ayudar´a de otra funci´on auxiliar que,
dada una cadena, obtiene otra donde se han eliminado los espacios en blanco.*/

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

void eraseElement(char array[], int &used, int pos){
    for (int i = pos; i < used-1; i++){
        array[i] = array[i+1];
    }
    used--;
}

void eraseSpaces(char array[], int &used){
    int i = 0;
    while (i < used){
        if (isspace(array[i])){
            eraseElement(array, used, i);
        }
        else i++;
    }
}

bool isPalindrome(char array[], int &used){
    eraseSpaces(array, used);
    bool is_palindrome = true;
    for (int i = 0; i < used/2 && is_palindrome; i++){
        if (array[i] != array[used-1-i]){
            is_palindrome = false;
        }
    }

    return is_palindrome;
}


int main(){
    const int limit = 100;
    char array[limit];
    int used;
    readArray(array, used, limit);

    bool is_pal = isPalindrome(array, used);

    if(is_pal){
        cout << "si" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}