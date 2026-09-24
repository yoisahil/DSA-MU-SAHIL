//Question.28


#include <iostream>
using namespace std;

int main() {
    int queue[10], front = -1, rear = -1;
    int choice, value;

    do {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;

            if (rear == 9) {
                cout << "Queue is Full";
            }
            else {
                if (front == -1)
                    front = 0;

                rear++;
                queue[rear] = value;

                cout << "Element added";
            }
        }

        else if (choice == 2) {
            if (front == -1 || front > rear) {
                cout << "Queue is Empty";
            }
            else {
                cout << "Deleted element: " << queue[front];
                front++;
            }
        }

        else if (choice == 3) {
            if (front == -1 || front > rear) {
                cout << "Queue is Empty";
            }
            else {
                cout << "Queue elements: ";
                for (int i = front; i <= rear; i++)
                    cout << queue[i] << " ";
            }
        }

    } while (choice != 4);

    return 0;
}