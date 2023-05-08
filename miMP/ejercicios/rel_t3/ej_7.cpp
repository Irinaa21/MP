/*Implemente las siguientes funciones sobre cadenas de caracteres estilo C usando aritmética de punteros
(sin usar el operador []):
(a) Función compararCadenas que compara dos cadenas. Devuelve un valor negativo si la primera es
más pequeña, positivo si es más grande y cero si son iguales.
(b) Función insertarCadena que inserte una cadena dentro de otra, en una posición dada.
Se supone que hay suficiente memoria en la cadena de destino.
Se supone que no es necesario pasar el tamaño de las cadenas (recordad que el carácter nulo delimita el
final de la cadena).*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int clen(const char *p){
    int n = 0;
    while (*(p+n) != '\0') n++;

    return n;
}

// positivo si el primero es mas grande
int compareCString(const char *a1, const char *a2){
    return clen(a1) - clen(a2);
}


void insertCString(char *output, const char *input, int pos){
    int o = clen(output);
    int in = clen(input);
    for (int i = pos; i < o; i++){
        output[i+in] = output[i];
    }

    for (int i = pos, j = 0; i < pos+in; i++, j++){
        output[i] = input[j];
    }
    *(output+o+in) = '\0';
}

void readCString(char *array, int limit, char tope = '#'){
    int i = 0;
    do{ 
        cin >> *(array+i);
        i++;
    } while(*(array+i-1) != tope);
    *(array+i-1) = '\0';
}

void printCString(const char *a){
    int i = 0;
    while (*(a+i) != '\0'){
        cout << *(a+i);
        i++;
    }
    cout << endl;
}


int main(){
    char o[100];
    char i[100];

    readCString(o, 100);
    readCString(i, 100);

    int n = compareCString(i, o);

    int pos;
    cin >> pos;

    insertCString(o, i, pos);

    printCString(o);
}