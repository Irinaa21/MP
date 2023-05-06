/*Implemente una funci´on mezclarUnico de tipo int que reciba como entrada dos arrays
ordenados de datos de tipo int y los mezcle en un tercer array. Tenga en cuenta que:
• Los arrays de entrada est´an ordenados y sin valores repetidos.
• El array de salida tendr´a los elementos ordenados y sin repetidos.
• Puede asumir que el array de salida tiene capacidad suficiente para todos los elementos.
• La funci´on devuelve un entero que es el n´umero de elementos que contiene el array
de salida. Nota: Ser´a menor o igual que la suma de los de entrada.*/

#include <iostream>
#include <string>

using namespace std;

void printArray(const int array[], int used){
    cout << used << endl;
    for (int i = 0; i < used; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void readArray(int array[], int &used, int limit){
    
    cin >> used;
    if (used > limit) used = limit;

    for (int i = 0; i < used && i < limit; i++){
        cin >> array[i];
    }
}

int merge(const int input1[], int used1,const int input2[], int used2, int output[]){
    int i = 0, j = 0, k = 0;
    while (i < used1 || j < used2){
        while ((j == used2 && i < used1) || (i < used1 && input1[i] <= input2[j])) {
            output[k++] = input1[i++]; 
        }
        if (input1[i-1] == input2[j]) j++;
        while ((j < used2 && i == used1) || (j < used2 &&  input2[j] <= input1[i])){
            output[k++] = input2[j++];
        }
        if (input1[i] == input2[j-1]) i++;
    }
    return k;
}

int merge(const int input1[], int used1,const int input2[], int used2, int output[]){
    int i = 0, j = 0, k = 0;
    for(int i=0; i<used1; i++){
        while(j < used2 && input2[j] < input1[i]){
            output[k++] = input2[j++];
        }
        if(input2[j-1] != input1[i])
            output[k++] = input1[i];
    }
    return k;
}


int main(){
    const int limit = 100;
    int a1[limit], a2[limit], merged[limit];
    int used1, used2;
    readArray(a1, used1, limit);
    readArray(a2, used2, limit);
    int used3 = merge(a1, used1, a2, used2, merged);

    printArray(merged, used3);
}