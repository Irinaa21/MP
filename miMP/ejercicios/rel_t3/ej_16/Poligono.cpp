/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Poligono.cpp
 * Author: irina
 * 
 * Created on May 9, 2023, 11:12 AM
 */

#include <cmath>
#include "Poligono.h"
#include "Punto.h"

using namespace std;

Poligono::Poligono(){
    allocate(0);
}

Poligono::Poligono(int n){
    allocate(n);
}

void Poligono::allocate(int n){
    delete[] vertices;
    if (n > 0){
        vertices = new Punto[n];
        nVertices = n;
    }
    else{
        vertices = nullptr;
        nVertices = 0;
    }
}

void Poligono::reallocate(int newSize){
    if (newSize > 0){
        Punto *aux = new Punto[newSize];
        for (int i = 0; i < nVertices && i < newSize; i++){
            aux[i] = vertices[i];
        }
        
        delete[] vertices;
        vertices = aux;
        nVertices = newSize;
    }
}

void Poligono::liberar(){
    delete[] vertices;
    nVertices = 0;
}

int Poligono::getNumeroVertices() const{
    return nVertices;
}

Punto Poligono::getVertice(int index) const{
    if (index < 0 || index >= nVertices){
        throw std::out_of_range("Punto Poligono::getVertice(int index) const");
    }
    
    return vertices[index];
}

void Poligono::addVertice(const Punto& v){
    reallocate(nVertices+1);
    vertices[nVertices - 1] = v;
}

double Poligono::getPerimetro() const{
    double sum = 0;
    for (int i = 0; i < nVertices; i++){
        sum += vertices[i].getDistance(vertices[(i+1)%nVertices]);
    }
    
    return sum;
}

double areaTriangulo(const Punto& pto1, const Punto& pto2, const Punto& pto3){
    double S1 = pto1.getDistance(pto2);
    double S2 = pto2.getDistance(pto3);
    double S3 = pto3.getDistance(pto1);
    
    double T = (S1 + S2 + S3) / 2;
    
    return sqrt(T * (T - S1) * (T - S2) * (T - S3));
}

double Poligono::getArea() const{
    double sum = 0;
    Punto interior = getPuntoInterior();
    for (int i = 1; i < nVertices-1; i++){
        sum += areaTriangulo(interior, vertices[i], vertices[i+1]);
    }
    return sum;
}

Punto Poligono::getPuntoInterior() const{
    return vertices[0];
}

void Poligono::print(ostream &flujo) const{
    flujo << nVertices << endl;
    for (int i = 0; i < nVertices; i++){
        vertices[i].print(flujo);
    }
}

void Poligono::leer(istream &flujo){
    flujo >> nVertices;
    allocate(nVertices);
    for (int i = 0; i < nVertices; i++){
        vertices[i].leer(flujo);
    }
}