#include <iostream>
using namespace std;

// creo que lo que no se puede hacer es cambiar el valor apuntado
// desde el puntero pero si le asignas la direccion de memoria de 
// un dato no constante puedes seguir cambiando el dato sin usar el 
// puntero
/*int main(){
    const int *p;
    int a;
    p = &a;
    cout << *p << endl;

    //*p = 7;
    a = 8;

    cout << *p << endl;
}*/

int main(){
    int entero=10;
    const int enteroConst=20;
    int *v1;
    const int *v3;
    v1 = &entero;
    v3 = &enteroConst;

    cout << *v1 << " " << *v3 << endl;

    int* const v2=v1;
    const int* const v4=v3;
    v1 = v2;
    //v1 = v3;
    //v1 = v4;      // v3 y v4 son punteros a enteros constantes y v1 no, por tanto 
                    // no se puede hacer la asignacion

    //int* const v2=v3;   

    const int* const v4=v3;
    //int* const v2=v4;


}