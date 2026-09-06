#include <iostream>
using namespace std;
int main() {
    //calculator program to perform basic arithmetic operations
    int a, b;
    cout<< "Enter the value of a: " << endl;
    cin>>a;
    cout<< "Enter the value of b: " << endl;
    cin>>b;

    cout<<"1-addition"<<endl;
    cout<<"2-subtraction"<<endl;
    cout<<"3-multiplication"<<endl;
    cout<<"4-division"<<endl;
    cout<<"5-modulus"<<endl;


    int choice;
    cout<<"Enter your choice: "<<endl;
    cin>>choice;

    switch(choice) {
        case 1:
            cout<<"addition: "<<a+b<<endl;
            break;
        case 2:
            cout<<"subtraction: "<<a-b<<endl;
            break;
        case 3:
            cout<<"multiplication: "<<a*b<<endl;
            break;
        case 4:
            cout<<"division: "<<a/b<<endl;
            break;
        case 5:
            cout<<"modulus: "<<a%b<<endl;
            break;
        default:
            cout<<"Invalid choice!"<<endl;
    }

    return 0;
}