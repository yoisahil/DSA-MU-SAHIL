//Question 29

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;

    // Insert first node
    Node* newNode = new Node();
    newNode->data = 10;
    newNode->next = head;
    head = newNode;

    cout << "Linked List: " << head->data;

    return 0;
}