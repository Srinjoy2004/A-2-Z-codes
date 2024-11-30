#include <iostream>
using namespace std;

// Definition of a node in the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Function to insert a new node at the end of the doubly linked list
Node* insertAtEnd(Node* head, int newData) {
    // Create a new node
    Node* newNode = new Node(newData);

    // If the list is empty, the new node becomes the head
    if (!head) {
        return newNode;
    }

    // Traverse to the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Update pointers to insert the new node at the end
    temp->next = newNode;
    newNode->prev = temp;

    return head; // Return the unchanged head
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

    // Insert nodes at the end
    head = insertAtEnd(head, 10);
    cout << "After inserting 10 at the end: ";
    printDoublyLinkedList(head);

    head = insertAtEnd(head, 20);
    cout << "After inserting 20 at the end: ";
    printDoublyLinkedList(head);

    head = insertAtEnd(head, 30);
    cout << "After inserting 30 at the end: ";
    printDoublyLinkedList(head);

    head = insertAtEnd(head, 40);
    cout << "After inserting 40 at the end: ";
    printDoublyLinkedList(head);

    return 0;
}
