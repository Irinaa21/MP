/*Realizar una función que lea un número natural y lo traduzca a morse. Se usa raya (-)
para codificar la señal larga y punto (.) para la señal corta. Los números se codifican de
la forma siguiente:
0 ----- 1 .---- 2 ..--- 3 ...-- 4 ....- 5 ..... 6 -.... 7 --... 8 ---.. 9 ----.
De esta forma, cada número en morse se representará en C++ por una cadena de 5
caracteres compuesta de puntos y rayas, según la tabla anterior.*/

#include <iostream>
#include <iostream>

using namespace std;

string digitMorse(int n){
    if (n > 9 || n < 0)
        throw std::out_of_range("string digitMorse(int n)");
    const string array[] = {"-----", ".----", "..---", "...--", "....-", 
                            ".....", "-....", "--...", "---..", "----."};
    return array[n];
}

string intToMorse(int n){
    string s;
    while (n / 10 != 0){
        s = digitMorse(n % 10) + " " + s;
        n = n / 10;
    }

    s = digitMorse(n) + " " + s;

    return s;
}


int main(){
    int n;

    cin >> n;

    cout << intToMorse(n);
}