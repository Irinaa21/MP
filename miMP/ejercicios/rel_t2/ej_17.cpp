
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

void printRow(const int *array, int used){
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

void readMatrix(int **&array, int &row, int &col){
    cin >> row >> col;

    array = new int*[row];
    for (int i = 0; i < row; i++){
        array[i] = new int[col];
    }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cin >> array[i][j];
        }
    }
}

void printMatrix(int **array, int row, int col){
    cout << row << " " << col << endl;
    for (int i = 0; i < row; i++){
        printRow(array[i], col);
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

//! Los punteros aunque sean como los arrays hay que pasarlos explicitamente por referencia
void transpose(int **&array, int &row, int &col){
    int **m = new int*[col];
    for (int i = 0; i < col; i++){
        m[i] = new int[row];
    }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            m[j][i] = array[i][j];
        }
    }

    for(int i = 0; i < row; ++i)
        delete[] array[i];

    delete[] array;

    int aux = row;
    row = col;
    col = aux;

    array = m;

}


int main(){
    
    int **array;
    int row, col;

    readMatrix(array, row, col);
    transpose(array, row, col);
    printMatrix(array, row, col);

    for(int i = 0; i < row; ++i)
        delete[] array[i];

    delete[] array;

}