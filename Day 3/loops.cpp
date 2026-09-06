// three types of loops are there:- 
// 1. for loop
// 2. while loop
// 3. do-while loop

//syntax of for loop:-
// for(initialization; condition; iteration){
//     //code to be executed
// }

//practice code for for loop
#include <iostream>
using namespace std;
int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name;

    for(int i=0; i<=5; i++){
        cout << name << endl;
    }
    return 0;
}