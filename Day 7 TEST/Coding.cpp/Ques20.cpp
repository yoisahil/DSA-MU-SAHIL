//Question 20

#include <iostream>
using namespace std;

int main() {
    int a[100], n, x, count = 0;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter element to find: ";
    cin >> x;

    for (int i = 0; i < n; i++) {
        if (a[i] == x)
            count++;
    }

    cout << "Frequency = " << count;

    return 0;
}