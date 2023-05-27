

#include "VectorSD.h"
using namespace std;

VectorSD::VectorSD() {
    delete[] info;
    info = new int[10];
    capacity = 10;
    used = 0;
}

VectorSD::VectorSD(int n) {
    if (n <= 0) n = 10;
    delete[] info;
    info = new int[n];
    capacity = n;
    used = 0;
}

int VectorSD::getData(int pos) const{
    if (pos < 0 || pos >= used){
        throw std::out_of_range("int VectorSD::getData(int pos) const");
    }
    return info[pos];
}

int VectorSD::nElements() const{
    return used;
}

void VectorSD::add(int num){
    if (used == capacity){
        reallocate(2*capacity);
    }
    info[used++] = num;
}

void VectorSD::copy(const VectorSD &v){
    int *aux = new int[capacity];
    for (int i = 0; i < used; i++){
        aux[i] = info[i];
    }

    deallocate();

    info = aux;
}

void VectorSD::reallocate(int newCapacity){
    if (newCapacity > 0){
        int *aux = new int[newCapacity];
        capacity = newCapacity;
        copy(*this);
    }
}

void VectorSD::deallocate(){
    delete[] info;
    info = nullptr;
}

void VectorSD::print(ostream &fout) const{
    for (int i = 0; i < used; i++){
        fout << info[i] << " ";
    }
    fout << endl;
}

void VectorSD::read(istream &fin){
    int num;
    while (fin >> num){
        add(num);
    }
}

VectorSD::~VectorSD() {
    deallocate();
}

