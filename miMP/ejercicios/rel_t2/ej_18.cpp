/*Calcular el producto de dos matrices A y B, suponiendo que A tiene m filas y n
columnas y B tiene n filas y p columnas.*/

#include <iostream>
#include <string>

using namespace std;

const int limit = 100;

void readMatrix(int array[limit][limit], int &row, int &column){
    cin >> row >> column;
    if (row > limit || column > limit) return;

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
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

void printMatrix(const int array[limit][limit], int row, int column){
    cout << row << " x " << column << endl;
    for (int i = 0; i < row; i++){
        printRow(array[i], column);
    }
}

void productMatrix(const int A[limit][limit], int rowA, int columnA, 
                    const int B[limit][limit], int rowB, int columnB, 
                    int output[limit][limit], int &row, int &column){
    if (columnA != rowB) return;
    row = rowA;
    column = columnB;

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            output[i][j] = 0;
            for (int k = 0; k < columnA; k++){
                output[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}


int main(){
    const int limit = 100;
    int A[limit][limit], B[limit][limit], O[limit][limit];
    int rowA, columnA, rowB, columnB, row = 0, column = 0;
    

    readMatrix(A, rowA, columnA);
    readMatrix(B, rowB, columnB);
    productMatrix(A, rowA, columnA, B, rowB, columnB, O, row, column);
    printMatrix(O, row, column);
}