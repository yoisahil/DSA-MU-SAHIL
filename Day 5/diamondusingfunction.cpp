#include <iostream>
using namespace std;

// Function to print upper half (including middle row)
void printUpperHalf(int n) {
    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        // Print stars
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

// Function to print lower half
void printLowerHalf(int n) {
    for (int i = n - 1; i >= 1; i--) {
        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        // Print stars
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

// Function to print full diamond
void printDiamond(int n) {
    printUpperHalf(n);
    printLowerHalf(n);
}

int main() {
    int n;
    cout << "Enter the number of rows for half diamond: ";
    cin >> n;

    printDiamond(n);

    return 0;
}