/*Haz un programa que calcule la traspuesta de una matriz 2D. La inversi´on se hace
por medio de una funci´on.*/

#include <iostream>
#include <string>

using namespace std;

const int limit = 100;

void readMatrix(int array[limit][limit], int &used){
    cin >> used;
    if (used > limit) return;

    for (int i = 0; i < used; i++){
        for (int j = 0; j < used; j++){
            cin >> array[i][j];
        }
    }
}

void printRow(const int array[], int used){
    for (int i = 0; i < used; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void printMatrix(const int array[limit][limit], int used){
    cout << used << endl;
    for (int i = 0; i < used; i++){
        printRow(array[i], used);
    }
}

void transpose(int array[limit][limit], int used){
    for (int i = 0; i < used; i++){
        for (int j = i+1; j < used; j++){
            int aux = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = aux;
        }
    }
}


int main(){
    const int limit = 100;
    int array[limit][limit];
    int used;

    readMatrix(array, used);
    transpose(array, used);
    printMatrix(array, used);
}