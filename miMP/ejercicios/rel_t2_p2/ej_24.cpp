/*Realizar una función que acepte una matriz de enteros y devuelva el número de columnas
únicas de la matriz, es decir, aquellas para las que NO existe otra columna en la matriz
con los mismos valores*/

#include <iostream>
#include <string>

using namespace std;

//!Metodo modificado, no coger de aqui
void readMatrix(int **&array, int &row, int &col){
    cin >> col >> row;

    array = new int*[row];
    for (int i = 0; i < row; i++){
        array[i] = new int[col];
    }

    for (int i = 0; i < col; i++){
        for (int j = 0; j < row; j++){
            cin >> array[j][i];
        }
    }
}


bool areIqual(int *a, int *b, int used_a, int used_b){
    bool are_iqual = true;

    if (used_a != used_b){
        are_iqual = false;
    }

    for (int i = 0; i < used_a && are_iqual; i++){
        if (a[i] != b[i]){
            are_iqual = false;
        }
    }

    return are_iqual;
}

int uniqueCol(int **matrix, int row, int col){
    int count = 0;
    bool *aux = new bool[row];
    for (int i = 0; i < row; i++){
        aux[i] = true;
    }

    for (int i = 0; i < row; i++){
        if(aux[i]){
            int *array = matrix[i];
            for (int j = i+1; j < row; j++){
                int *array_aux = matrix[j];
                if (areIqual(array, array_aux, col, col)){
                    aux[j] = aux[i] = false;
                }
            }
            
            if(aux[i]) count++;
        }
    }

    return count;
}


int main(){
    
    int **array;
    int row, col;

    readMatrix(array, row, col);
    int n = uniqueCol(array, row, col);
    cout << n << endl;


    for(int i = 0; i < row; ++i)
        delete[] array[i];

    delete[] array;

}