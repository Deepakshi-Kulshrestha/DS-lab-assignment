#include <iostream>
#define SIZE 5
using namespace std;

class SimpleQueue {
    int arr[SIZE];
    int front, rear;

public:
    SimpleQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }
        if (isEmpty())
            front = 0;
        arr[++rear] = x;
        cout << "Enqueued " << x << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Dequeued: " << arr[front++] << endl;
    }

    void peek() {
        if (!isEmpty())
            cout << "Front: " << arr[front] << endl;
        else
            cout << "Queue is Empty\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        for (int i = front; i <= rear; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    SimpleQueue q;
    int choice, value;
    do {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\nEnter Choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; q.enqueue(value); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: q.display(); break;
            case 5: break;
            default: cout << "Invalid Choice\n";
        }
    } while (choice != 5);
    return 0;
}

