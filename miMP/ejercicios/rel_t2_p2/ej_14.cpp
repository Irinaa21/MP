#include <iostream>
#include <string>

using namespace std;

const int limit = 100;

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
/*10 12 14 16 
  20 22 24 26
  30 32 34 36 */
void Forma1(int array[limit][limit], int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            array[i][j] = 10 * (i+1) + j*2;
        }
    }
}


/*10 12 14 16 
  20 22  0  0
   0  0  0  0 */
void Forma2(int array[limit][limit], int row, int col){
    int count = 0;
    
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (count < (row*col)/2)
                array[i][j] = 10 * (i+1) + j*2;
            else array[i][j] = 0;
            count++;
        }
    }
}

/*Definir una matriz tridimensional 10 × 10 × 10 de enteros. Asignar en cada posición
(i, j, k) la suma de los tres ı́ndices.*/

void Forma3(int array[limit][limit][limit]){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            for (int k = 0; k < 10; k++){
                array[i][j][k] = i+j+k;
            }
        }
    }
}


int main(){
    int array1[limit][limit], array2[limit][limit], array3[limit][limit][limit];
    Forma1(array1, 3, 4);
    Forma2(array2, 3, 4);
    Forma3(array3);

    printMatrix(array1, 3, 4);
    printMatrix(array2, 3, 4);
}