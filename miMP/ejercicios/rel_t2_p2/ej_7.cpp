/*Construir una funci´on que dada una cadena de caracteres cad y dos valores enteros pos
y tam modifique cad eliminando los tam caracteres empezando en la posici´on pos.
Razonar sobre todos los casos posibles que pueden suceder.*/

/*
- Que pos se salga del array, sea menor que 0 o mayor o igual que used
- Que a partir de pos hay menos o igual caracteres de los que se quieren borrar ->
en ese caso borrariamos todo a partir de pos.
- El caso normal que seria que simplemente tengamos que borrar ciertos elementos
del medio de la cadena*/

#include <iostream>
#include <string>

using namespace std;

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
    used = i-1;
}

void eraseElements(char array[], int &used, int pos, int tam){
    if (pos >= used || pos < 0){
        throw std::out_of_range("Out of range");
    }

    if (pos + tam >= used) used = pos;
    else{
        for (int i = pos + tam; i < used; i++){
            array[i-tam] = array[i];
        }
        used -= tam;
    }
}


int main(){
    const int limit = 100;
    char array[limit];
    int used;

    readArray(array, used, limit);

    int pos, tam; 
    cin >> pos >> tam;

    eraseElements(array, used, pos, tam);

    printArray(array, used);
}