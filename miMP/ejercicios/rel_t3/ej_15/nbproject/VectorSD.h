
#ifndef VECTORSD_H
#define VECTORSD_H

#include <fstream>
#include <iostream>


class VectorSD {
public:
    VectorSD();
    VectorSD(int n);
    int getData(int pos) const;
    int nElements() const;
    void add(int num);
    void copy(const VectorSD &v);
    void reallocate(int newCapacity);
    void deallocate();
    void print(std::ostream &fout) const;
    void read(std::istream &fin); 
    ~VectorSD();
private:
    int *info; // array dinámico de int
    int used; // nº de enteros actualmente en el array
    int capacity; // capacidad del array
};

#endif /* VECTORSD_H */

