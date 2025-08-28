#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX], top = -1;

bool isEmpty() { return top == -1; }
bool isFull() { return top == MAX - 1; }

void push(int val) {
    if (isFull())
        cout << "Stack Overflow!\n";
    else
        stack[++top] = val;
}

void pop() {
    if (isEmpty())
        cout << "Stack Underflow!\n";
    else
        cout << "Popped: " << stack[top--] << endl;
}

void peek() {
    if (isEmpty())
        cout << "Stack is empty!\n";
    else
        cout << "Top element: " << stack[top] << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty!\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--)
        cout << stack[i] << " ";
    cout << endl;
}

int main() {
    int choice, val;
    do {
        cout << "\nStack Menu\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; push(val); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case

