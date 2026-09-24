//swapping two variables without using third variable using functions.

#include<iostream>
using namespace std; 

void swap(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int main() {
    int x = 5, y = 10;

    cout << "Before: x = " << x << ", y = " << y << endl;
    swap(x, y);
    cout << "After: x = " << x << ", y = " << y << endl;

    return 0;
}