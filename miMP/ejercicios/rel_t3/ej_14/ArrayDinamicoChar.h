

#ifndef ARRAYDINAMICOCHAR_H
#define ARRAYDINAMICOCHAR_H
#include <fstream>


#endif /* ARRAYDINAMICOCHAR_H */

void inicializar(char *&p, int n);

void liberar(char *p, int &n);

void mostrar(std::ostream &flujo, char *array, int n);

void redimensionar(char *&array, int &n, int aumento);

void aniadir(char *&array, int &n, char a);

void leer(std::istream& flujo, char* &array, int& nchar);
