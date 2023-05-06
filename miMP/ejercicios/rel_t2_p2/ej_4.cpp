/*Dado un array de n´umeros reales, realizar una funci´on que determine el primer y segundo
elemento de mayor valor*/

#include <iostream>
#include <string>

using namespace std;

void printArray(const double array[], int used){
    cout << used << endl;
    for (int i = 0; i < used; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void readArray(double array[], int &used, int limit){
    cin >> used;
    if (used > limit) used = limit;

    for (int i = 0; i < used && i < limit; i++){
        cin >> array[i];
    }
}

void max2(const double array[], int used, double &first, double &second){
    if (array[0] > array[1]){
        first = array[0];
        second = array[1];
    }
    else{
        first = array[1];
        second = array[0];
    }
    for (int i = 2; i < used; i++){
        if (array[i] > first){
            second = first;
            first = array[i];
        }
        else if (array[i] > second){
            second = array[i];
        }
    }
}


int main(){
    const int limit = 100;
    double array[limit];
    int used;
    double first, second;

    readArray(array, used, limit);

    max2(array, used, first, second);

    cout << first << " " << second;
}