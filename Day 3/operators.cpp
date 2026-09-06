// operators are the symbols used to perform operation between operands.
//arithmatic operators oprators are used to perform basic mathematical operations
// like addition, subtraction, multiplication, division, and modulus.

#include <iostream>
using namespace std;
int main() {
    int a ,b;
    cout<< "Enter the value of a: "<<endl;
    cin>>a;
    cout<< "Enter the value of b: "<<endl;
    cin>>b;
    //ADDITION
    cout<< "Addition: "<<a+b<<endl;
    //SUBTRACTION
    cout<< "Subtraction: "<<a-b<<endl;
    //MULTIPLICATION
    cout<< "Multiplication: "<<a*b<<endl;
    //DIVISION
    cout<< "Division: "<<a/b<<endl;
    //MODULUS
    cout<< "Modulus: "<<a%b<<endl;

    return 0;
}