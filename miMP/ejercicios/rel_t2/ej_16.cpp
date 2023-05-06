/*Haz un programa que calcule, mediante una funci´on, la traza de una matriz 2D (suma
de los elementos de la diagonal principal).*/

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

int matrixTrace(const int array[limit][limit], int used){
    int sum = 0;
    for (int i = 0; i < used; i++){
        sum += array[i][i];
    }

    return sum;
}


int main(){
    const int limit = 100;
    int array[limit][limit];
    int used;

    readMatrix(array, used);
    int trace = matrixTrace(array, used);
    cout << trace << endl;
    //printMatrix(array, used);
}