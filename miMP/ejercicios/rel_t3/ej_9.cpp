/*Orden creciente o decreciente para el algoritmo de ordenacion con un puntero a funcion*/

#include <iostream>
using namespace std;

bool Increasing(int a, int b){
    return a > b;
}

bool Decreasing(int a, int b){
    return a < b;
}

void swap(const int *v[], int i, int j){
    const int *aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void bubbleSort(const int *v[], int used, bool (*compare)(int,int)){
    bool change = true;
    for (int i = used-1; i > 0 && change; i--){
        change = false;
        for (int j = 0; j < i; j++){
            if ((*compare)(*v[j], *v[j+1])){
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
    const int limit = 100;
    int array[limit];
    const int *p[limit];
    int used;
    
    readArray(array, used, limit);
    apuntaAArray(p, array, used, 0, used);

    bubbleSort(p, used, Decreasing);

    printArray(p, used);
}