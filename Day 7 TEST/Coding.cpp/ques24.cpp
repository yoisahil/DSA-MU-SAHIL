//Question 24.

#include <iostream>
using namespace std;

int main() {
    int a[50], b[50], c[100];
    int n1, n2, k = 0;

    cout << "Enter size of first array: ";
    cin >> n1;

    cout << "Enter first array: ";
    for (int i = 0; i < n1; i++)
        cin >> a[i];

    cout << "Enter size of second array: ";
    cin >> n2;

    cout << "Enter second array: ";
    for (int i = 0; i < n2; i++)
        cin >> b[i];

    for (int i = 0; i < n1; i++)
        c[k++] = a[i];

    for (int i = 0; i < n2; i++)
        c[k++] = b[i];

    cout << "Merged array: ";
    for (int i = 0; i < k; i++)
        cout << c[i] << " ";

    return 0;
}