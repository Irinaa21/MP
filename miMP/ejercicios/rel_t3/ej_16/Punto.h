/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Punto.h
 * Author: irina
 *
 * Created on May 9, 2023, 11:11 AM
 */

#ifndef PUNTO_H
#define PUNTO_H

#include <fstream>
#include <iostream>

class Punto {
public:
    Punto();
    Punto(double x, double y);
    double getX() const;
    double getY() const;
    void setXY(double x, double y);
    double getDistance(const Punto &otro) const;
    void print(std::ostream &flujo) const;
    void leer(std::istream &flujo);

private:
    double x;
    double y; 
};

#endif /* PUNTO_H */

