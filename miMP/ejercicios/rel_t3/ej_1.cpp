#include <iostream>

using namespace std;

/*int main(){
    int a = 5, *p;
    cout << *p << endl;
    a = *p * a;

    if (a == *p) cout << "iguales" << endl;
    else cout << "distintos" << endl;
    cout << *p << endl << a << endl;

    return 0;
}*/

/*int main(){
    int a = 5, *p;
    *p = *p * a;

    if (a == *p) cout << "iguales" << endl;
    else cout << "distintos" << endl;

    return 0;
}*/

/*int main(){
    int a = 5, *p = &a;
    cout << *p << endl;
    *p = *p * a;

    if (a == *p) cout << "iguales" << endl;
    else cout << "distintos" << endl;
    cout << *p << endl << a << endl;
    return 0;
}*/

int main(){
    int a = 5, *p = &a, **p2 = &p;
    **p2 = *p + (**p2 / a);
    *p = a+1;
    a = **p2 / 2;
    cout << "a es igual a: " << a << endl;
    return 0;
}