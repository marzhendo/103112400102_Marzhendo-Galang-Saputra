#include <iostream>

using namespace std;

void pola(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < (n - i); j++) {
            cout << " ";
        }
        for (int k = i; k >= 1; k--) {
            cout << k;
        }
        cout << " * ";

         for (int k = 1; k <= i; k++){
            cout << k;
        }
        cout << endl;
    }
    for (int k = 0; k < (n-1); k++) {
        cout << " ";
    }
    cout << "  *" << endl;
}

int main() {
    int n;
    cout << "Masukkan input: ";
    cin >> n;
    cout << "Output: " << endl;
    pola(n);
}