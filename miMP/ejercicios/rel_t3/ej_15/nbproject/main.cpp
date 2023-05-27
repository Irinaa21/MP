#include <cstdlib>
#include <iostream>
#include "VectorSD.h"


using namespace std;


int main(int argc, char *argv[])
{
    VectorSD v;
    if (argc==1)
        v.read(cin);
    else {
        ifstream flujo;
        flujo.open(argv[1]);
        if (!flujo) {
            cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
            return 1;
        }
        v.read(flujo);
        flujo.close();
    }
    v.print(cout);
    v.deallocate(); // Libera la memoria dinámica reservada
}

