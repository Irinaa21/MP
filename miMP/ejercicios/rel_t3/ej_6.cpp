/*Dado un array de 10 elementos, haz un bucle que busque el máximo y el mı́nimo (sin usar el operador
[]). Al acabar el bucle tendremos un puntero apuntando a cada uno de ellos.*/

#include <iostream>
using namespace std;

void minMaxArray(int *p, int used, int *&min, int *&max){
    /*for (int i = 0; i < used; i++){
        cout << "hola " << p[i] << endl;
    }*/
    min = max = p;
    int min_aux = *p, max_aux = *p;
    //cout << "tu puta madre " << min_aux << " xd " << max_aux << endl; 
    for (int i = 1; i < used; i++){
        //cout << "no se que hago con mi vida " << *(p+i) << endl;
        if (*(p+i) > max_aux){
            max = (p+i);
            max_aux = *(p+i);
        }
        else if (*(p+i) < min_aux){
            min = (p+i);
            min_aux = *(p+i);
        }
    }

    //cout << "uwu " << *min << " uwu " << *max << endl;
}

void readArray(int *p, int &used, int limit){
    cin >> used;
    if (used > limit) used = limit;

    for (int i = 0; i < used; i++){
        cin >> *(p+i);
    }
}

int main(){
    const int limit = 10;
    int array[limit];
    int used;
    readArray(array, used, limit);

    int *min, *max;

    minMaxArray(array, used, min, max);

    //cout << *array << endl;

    cout << *min << " " << *max << endl;
}