#include <iostream>
using namespace std;

void tukar(int *x, int *y, int *z) {
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;

}
int main() {
    int a = 12, b = 15, c = 17;
    int *ptr;
    ptr = &a;

    cout << "Nilai dari a: " << a << endl;
    cout << "Alamat dari a: " << &a << endl;
    cout << "Nilai tersimpan di pointer (alamat a): " << ptr << endl;
    cout << "Nilai yang ditunjuk pointer: " << *ptr << endl;

    tukar(&a, &b, &c);
    cout << "Setelah swap\nnilai dari a = " << a << "\nnilai dari b = " << b << "\nnilai dari c = " << c << endl;
    return 0;
}