#include <iostream>
using namespace std;

// Definition of a node in the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Function to insert a new node before the head of the doubly linked list
Node* insertBeforeHead(Node* head, int newData) {
    // Create a new node
    Node* newNode = new Node(newData);

    // If the list is empty, the new node becomes the head
    if (!head) {
        return newNode;
    }

    // Update pointers to insert before the head
    newNode->next = head;
    head->prev = newNode;

    // Update the head to the new node
    return newNode;
}

// Function to print the doubly linked list
void printDoublyLinkedList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Driver code
int main() {
    Node* head = nullptr;

    // Insert before head in an empty list
    head = insertBeforeHead(head, 10);
    cout << "After inserting 10: ";
    printDoublyLinkedList(head);

    // Insert before head in a non-empty list
    head = insertBeforeHead(head, 20);
    cout << "After inserting 20: ";
    printDoublyLinkedList(head);

    head = insertBeforeHead(head, 30);
    cout << "After inserting 30: ";
    printDoublyLinkedList(head);

    return 0;
}
