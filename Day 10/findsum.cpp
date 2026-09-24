//Sum of array elements and average.
#include <iostream>
using namespace std;
int main()
{ 
    int n, sum = 0;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    double average = static_cast<double>(sum) / n;
    cout << "Sum of array elements: " << sum << endl;
    cout << "Average of array elements: " << average << endl;
    return 0;
}