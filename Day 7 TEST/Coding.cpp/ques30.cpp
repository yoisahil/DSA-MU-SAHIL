//Question 30

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = new Node{10, NULL};
    head->next = new Node{20, NULL};
    head->next->next = new Node{30, NULL};

    int value;
    cout << "Enter value to search: ";
    cin >> value;

    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Value found";
            return 0;
        }
        temp = temp->next;
    }

    cout << "Value not found";

    return 0;
}