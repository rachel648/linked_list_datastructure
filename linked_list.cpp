
#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Insert a new node at the beginning of the linked list
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << "Node with value " << value << " inserted." << endl;
    }

    // Delete a node with a given value from the linked list
    void remove(int value) {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Node with value " << value << " not found in the linked list." << endl;
            return;
        }

        if (previous == nullptr)
            head = current->next;
        else
            previous->next = current->next;

        delete current;
        cout << "Node with value " << value << " removed from the linked list." << endl;
    }

    // Display the linked list
    void display() {
        Node* current = head;

        if (current == nullptr) {
            cout << "Linked list is empty." << endl;
            return;
        }

        cout << "Linked list: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList linkedList;

    linkedList.display();

    linkedList.insert(5);
    linkedList.insert(10);
    linkedList.insert(15);

    linkedList.display();

    linkedList.remove(10);
    linkedList.remove(20);

    linkedList.display();

    return 0;
}

