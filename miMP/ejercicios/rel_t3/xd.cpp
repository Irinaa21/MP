#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v(10),v2(5);
    for (int i = 0; i < 10; i++){
        v[i] = i;
    }
    v[10] = 8;
    cout << v2[0] << endl;

    cout << v[-1] << endl;
}