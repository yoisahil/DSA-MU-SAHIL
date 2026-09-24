//Question 22

#include <iostream>
using namespace std;

int main() {
    int a[5], temp;

    cout << "Enter 5 elements: ";
    for(int i = 0; i < 5; i++)
        cin >> a[i];

    for(int i = 0; i < 2; i++) {
        temp = a[i];
        a[i] = a[4-i];
        a[4-i] = temp;
    }

    cout << "Reversed array: ";
    for(int i = 0; i < 5; i++)
        cout << a[i] << " ";

    return 0;
}