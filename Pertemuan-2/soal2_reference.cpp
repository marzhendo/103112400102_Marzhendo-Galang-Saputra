#include <iostream>
using namespace std;

void tukar(int &x, int &y, int &z) {
    int temp;
    temp = x;
    x = y;
    y = z;
    z = temp;
}
int main() {
    int a = 10, b = 20, c = 30;
    int& ref = a;
    cout << "Nilai a: " << a << endl;
    cout << "Alamat a: " << &a << endl;
    cout << "Nilai ref: " << ref << endl;
    cout << "Alamat ref: " << &ref << endl;

    ref = 15;
    cout << "Setelah ref = 15\n";
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar(a, b, c);
    cout << "Setelah swap\nNilai a: " << a << "\nNilai b: " << b << "\nNilai c: " << c << endl;
    return 0;
}