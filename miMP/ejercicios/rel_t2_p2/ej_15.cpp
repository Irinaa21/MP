/*Realizar un programa modular que rellene una matriz bidimensional 7 × 5 de enteros con
datos aleatorios e imprima por pantalla el número mayor y menor de la matriz y sus
posiciones (fila y columna).*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

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

void printMatrix(const int array[limit][limit], int row, int col){
    cout << row << " x " << col << endl;
    for (int i = 0; i < row; i++){
        printRow(array[i], col);
    }
}

void generateArray(int array[], int used){
    srand(time(NULL));
    for (int i = 0; i < used; i++){
        array[i] = rand();
    }
}

void generateMatrix(int matrix[limit][limit], int row, int col){
    for (int i = 0; i < row; i++){
        generateArray(matrix[i], col);
    }
}

void MinMaxArray(const int array[], int used, int &pos_min, int &pos_max, int &min, int &max){
    min = max = array[0];
    for (int i = 1; i < used; i++){
        if (array[i] < min){
            min = array[i];
            pos_min = i;
        }
        if (array[i] > max){
            max = array[i];
            pos_max = i;
        }
    }
}

void MinMaxMatrix(const int matrix[][limit], int row, int col, int &min, int &max, 
                int &pos_min_row, int &pos_min_col, int &pos_max_row, int &pos_max_col){
    //Asegnamos la primera posicion como maximo y minimo por defecto
    max = min = matrix[0][0];
    pos_max_col = pos_max_row = pos_min_col = pos_min_row = 0;

    // Buscamos el minimo y el maximo de cada fila con la función auxiliar y si es menor o mayor que los
    // registrados lo vamos guardando
    for (int i = 0; i < row; i++){
        int aux_col_min, aux_col_max, min_aux, max_aux;
        MinMaxArray(matrix[i], col, aux_col_min, aux_col_max, min_aux, max_aux);
        if (max_aux > max){
            max = max_aux;
            pos_max_col = aux_col_max;
            pos_max_row = i;
        }
        if (min_aux < min){
            min = min_aux;
            pos_min_col = aux_col_min;
            pos_min_row = i;
        }
    }
}

