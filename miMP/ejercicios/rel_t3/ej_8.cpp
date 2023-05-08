/*Escriba una función ordenacionPorBurbuja() que reciba como entrada un array de números junto con
su longitud y que nos devuelva un array de punteros a los elementos del array de entrada de forma que
los elementos apuntados por dicho array de punteros estén ordenados
Note que el array de punteros debe ser un parámetro de la función, y estar reservado previamente a la
llamada con un tamaño, al menos, igual al del array. Una vez escrita la función, considere la siguiente
declaración:
int vec [1000];
int *ptr [1000];
y escriba un trozo de código que, haciendo uso de la función, permita
(a) Ordenando punteros, mostrar los elementos del array, ordenados.
(b) Ordenando punteros, mostrar los elementos de la segunda mitad del array, ordenados.
sin modificar el array de datos vec.*/

#include <iostream>
using namespace std;

void swap(const int *v[], int i, int j){
    const int *aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void bubbleSort(const int *v[], int used){
    bool change = true;
    for (int i = used-1; i > 0 && change; i--){
        change = false;
        for (int j = 0; j < i; j++){
            if (*v[j] > *v[j+1]){
                swap(v, j, j+1);
                change = true; 
            }
        }
    }
}

void apuntaAArray(const int *p[], const int v[], int used, int begin, int end){
    for (int i = 0; i < used-begin; i++){
        p[i] = &v[i+begin];
    }
}



void printArray(const int *v[], int used){
    cout << used << endl;
    for (int i = 0; i < used; i++){
        cout << *v[i] << " ";
    }
    cout << endl;
}
void printArray(const int v[], int used){
    cout << used << endl;
    for (int i = 0; i < used; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void readArray(int v[], int &used, int limit){
    cin >> used;
    if (used > limit) used = limit;

    for (int i = 0; i < used; i++){
        cin >> v[i];
    }
}

int main(){
    int vec [1000];
    const int *ptr [1000];
    int used;

    readArray(vec, used, 1000);
    printArray(vec, used);
    apuntaAArray(ptr, vec, used, 0, used);
    const int *ptr2[500];
    apuntaAArray(ptr2, vec, used, used/2, used);

    bubbleSort(ptr, used);
    bubbleSort(ptr2, used/2);

    printArray(ptr, used);
    printArray(ptr2, used/2);

}