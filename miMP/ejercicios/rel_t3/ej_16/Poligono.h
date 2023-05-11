/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Poligono.h
 * Author: irina
 *
 * Created on May 9, 2023, 11:12 AM
 */

#ifndef POLIGONO_H
#define POLIGONO_H

#include <fstream>
#include <iostream>
#include "Punto.h"

class Poligono{
    int nVertices; // Número de puntos en el array dinámico
    Punto *vertices; // Array dinámico de objetos Punto
public:
    Poligono();
    Poligono(int n);
    void allocate(int n);
    void reallocate(int newSize);
    void liberar();
    int getNumeroVertices() const;
    Punto getVertice(int index) const;
    void addVertice(const Punto& v);
    double getPerimetro() const;
    double getArea() const;
    Punto getPuntoInterior() const ;
    void print(std::ostream &flujo) const;
    void leer(std::istream &flujo);
};


double areaTriangulo(const Punto& pto1, const Punto& pto2, const Punto& pto3);

#endif /* POLIGONO_H */

