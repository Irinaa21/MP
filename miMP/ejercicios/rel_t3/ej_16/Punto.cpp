/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Punto.cpp
 * Author: irina
 * 
 * Created on May 9, 2023, 11:11 AM
 */

#include <fstream>
#include <cmath>
#include "Punto.h"

using namespace std;

Punto::Punto() : x(0), y(0) {}

Punto::Punto(double x, double y) {this -> x = x; this -> y = y;}

double Punto::getX() const {
    return x;
}

double Punto::getY() const {
    return y;
}

void Punto::setXY(double x, double y){
    this -> x = x;
    this -> y = y;
}

double Punto::getDistance(const Punto &otro) const{
    return sqrt((otro.getX() - getX())*(otro.getX() - getX()) + (otro.getY() - getY())*(otro.getY() - getY()));
}

void Punto::print(ostream &flujo)const {
    flujo << getX() << " " << getY() << endl;
}

void Punto::leer(istream &flujo){
    double _x, _y;
    flujo >> _x >> _y;
    setXY(_x, _y);
}

