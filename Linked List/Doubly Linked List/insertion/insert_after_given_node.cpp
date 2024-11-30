#include <iostream>
using namespace std;

// Definition of a node in the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Function to insert a new node after a given node
void insertAfterNode(Node* givenNode, int newData) {
    if (!givenNode) {  // If the given node is nullptr, do nothing
        cout << "The given node is nullptr!" << endl;
        return;
    }

    // Create a new node
    Node* newNode = new Node(newData);

    // Point the new node's prev to the given node
    newNode->prev = givenNode;

    // Point the new node's next to the next of the given node
    newNode->next = givenNode->next;

    // If the given node is not the last node, update the next node's prev pointer
    if (givenNode->next) {
        givenNode->next->prev = newNode;
    }

    // Set the given node's next pointer to the new node
    givenNode->next = newNode;
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

// Helper function to create a doubly linked list from an array
Node* arrayToDoublyLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < size; i++) {
        Node* newNode = new Node(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    return head;
}

// Driver code
int main() {
    // Create a doubly linked list from an array
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = arrayToDoublyLinkedList(arr, size);

    cout << "Original List: ";
    printDoublyLinkedList(head);

    // Suppose we want to insert a node with data '6' after the node with data '3'
    Node* givenNode = head->next->next;  // node with data '3'

    // Insert after the given node
    insertAfterNode(givenNode, 6);

    cout << "After inserting 6 after the node with data 3: ";
    printDoublyLinkedList(head);

    return 0;
}
