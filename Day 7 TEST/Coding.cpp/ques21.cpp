//Question 21

#include <iostream>
using namespace std;

int main() {
    int a[100], n, small;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    small = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < small)
            small = a[i];
    }

    cout << "Smallest element = " << small;

    return 0;
}