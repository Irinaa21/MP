#include <iostream>
#include <fstream> // ifstream
#include "ArrayDinamicoChar.h"
using namespace std;
int main(int argc, char *argv[])
{
    char* arraychar;
    int nCaracteres = 0;
    inicializar(arraychar, nCaracteres);
    if (argc==1)
        leer(cin, arraychar, nCaracteres);
    else {
        ifstream flujo;
        flujo.open(argv[1]);
        if (!flujo) {
            cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
            return 1;
        }
        leer(flujo, arraychar, nCaracteres);
        flujo.close();
    }
    mostrar(cout, arraychar, nCaracteres);
    liberar(arraychar, nCaracteres); // Libera la memoria dinámica reservada
}


