//QUESTION 17.


#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num, original, remainder, sum = 0, digits = 0;

    cout << "Enter a number: ";
    cin >> num;

    original = num;
    int temp = num;

    // Count digits
    while (temp != 0) {
        digits++;
        temp = temp / 10;
    }

    temp = num;

    // Calculate Armstrong sum
    while (temp != 0) {
        remainder = temp % 10;
        sum = sum + pow(remainder, digits);
        temp = temp / 10;
    }

    if (sum == original)
        cout << original << " is an Armstrong number";
    else
        cout << original << " is not an Armstrong number";

    return 0;
}