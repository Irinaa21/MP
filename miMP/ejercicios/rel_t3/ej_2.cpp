#include <iostream>

using namespace std;

void power2(int *&p){
    *p = *p * *p;
    p = nullptr;
}

int main(){
    int a = 5, *p = &a;

    power2(p);

    cout << a << endl << p << endl;
}