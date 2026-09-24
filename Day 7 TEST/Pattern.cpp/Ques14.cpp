//QUestion.14


#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        // Print spaces
        for (int j = 1; j <= N - i; j++)
            cout << " ";

        // Print stars
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << "*";

        cout << endl;
    }

    return 0;
}