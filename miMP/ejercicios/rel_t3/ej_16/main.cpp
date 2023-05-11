/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: irina
 *
 * Created on May 9, 2023, 11:08 AM
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Poligono.h"
#include "Punto.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    if (argc != 2){
        cerr << "Ejecutar con un fichero de entrada" << endl;
        return 1;
    }
    
    Poligono pol;
    ifstream input;
    
    input.open(argv[1]);
    if (!input){
        cerr << "Fichero " << argv[1] << " invalido" << endl;
        return 1;
    }
    
    pol.leer(input);
    
    double per, area;
    per = pol.getPerimetro();
    area = pol.getArea();
    
    pol.print(cout);
    
    cout << "Area: " << area << endl << "Perimetro: " << per << endl;
}

