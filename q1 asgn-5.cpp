#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // (a) Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
    }

    // (b) Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // (c) Insert before/after specific value
    void insertBeforeAfter(int target, int value, bool before) {
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr) {
            cout << "List is empty.\n";
            delete newNode;
            return;
        }

        if (before) {
            if (head->data == target) {
                newNode->next = head;
                head = newNode;
                return;
            }
            Node* prev = head;
            Node* curr = head->next;
            while (curr && curr->data != target) {
                prev = curr;
                curr = curr->next;
            }
            if (curr) {
                prev->next = newNode;
                newNode->next = curr;
            } else {
                cout << "Target not found.\n";
                delete newNode;
            }
        } else {
            Node* curr = head;
            while (curr && curr->data != target)
                curr = curr->next;

            if (curr) {
                newNode->next = curr->next;
                curr->next = newNode;
            } else {
                cout << "Target not found.\n";
                delete newNode;
            }
        }
    }

    // (d) Delete from beginning
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // (e) Delete from end
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    // (f) Delete specific node
    void deleteNode(int value) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* prev = head;
        Node* curr = head->next;
        while (curr && curr->data != value) {
            prev = curr;
            curr = curr->next;
        }
        if (curr) {
            prev->next = curr->next;
            delete curr;
        } else {
            cout << "Node not found.\n";
        }
    }

    // (g) Search node
    void search(int value) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == value) {
                cout << "Found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Not found.\n";
    }

    // (h) Display list
    void display() {
        Node* temp = head;
        if (!temp) {
            cout << "List is empty.\n";
            return;
        }
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    Node* getHead() {
        return head;
    }

    void setHead(Node* h) {
        head = h;
    }
};

// --- Menu for Question 1 ---
void runMenu() {
    LinkedList list;
    int choice, value, target;
    bool before;

    do {
        cout << "\n--- MENU ---\n"
             << "1. Insert at Beginning\n"
             << "2. Insert at End\n"
             << "3. Insert Before/After Value\n"
             << "4. Delete from Beginning\n"
             << "5. Delete from End\n"
             << "6. Delete Specific Node\n"
             << "7. Search for Node\n"
             << "8. Display List\n"
             << "9. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; list.insertAtBeginning(value); break;
            case 2: cout << "Enter value: "; cin >> value; list.insertAtEnd(value); break;
            case 3:


