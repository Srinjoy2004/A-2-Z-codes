#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert before a value X
void insertBeforeX(Node*& head, int data, int X) {
    Node* newNode = new Node();
    newNode->data = data;

    // Case 1: Insert before the head (if head contains X)
    if (head != nullptr && head->data == X) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    // Traverse to find X while keeping track of the previous node
    while (temp != nullptr && temp->data != X) {
        prev = temp;
        temp = temp->next;
    }

    // Case 2: X not found
    if (temp == nullptr) {
        cout << "Value " << X << " not found in the list." << endl;
        delete newNode; // Clean up memory
        return;
    }

    // Case 3: Insert before X
    prev->next = newNode;
    newNode->next = temp;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    Node* head = nullptr;

    // Creating a sample linked list
    insertBeforeX(head, 10, 1); // Insert into an empty list (value not found case)
    insertBeforeX(head, 20, 10); // Insert before 10
    insertBeforeX(head, 30, 20); // Insert before 20

    cout << "Linked list after insertions:" << endl;
    printList(head);

    return 0;
}
