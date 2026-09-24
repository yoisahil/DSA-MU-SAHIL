#include <iostream>
using namespace std;

int main() {
    int n = 4;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n - i; j++)
            cout << " ";
        for (int k = 0; k < 2 * (n-i) + 1; k++)
            cout << "*";
        cout << endl;
    }

    return 0;
}