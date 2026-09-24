//Question 16.


#include <iostream>
using namespace std;

int main() {
    int N, sum = 0;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        sum = sum + i;
    }

    cout << "Sum = " << sum;

    return 0;
}