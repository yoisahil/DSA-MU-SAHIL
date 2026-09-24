//Question.23

#include <iostream>
using namespace std;

int main() {
    int a[100], n;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                for (int k = j; k < n - 1; k++)
                    a[k] = a[k + 1];

                n--;
                j--;
            }
        }
    }

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}