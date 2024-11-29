#include <iostream>
using namespace std;

// Definition of a node in the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    // Constructor to initialize a node
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Function to convert an array to a doubly linked list
Node* arrayToDoublyLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;

    // Create the head of the linked list
    Node* head = new Node(arr[0]);
    Node* current = head;

    // Iterate through the array and create nodes
    for (int i = 1; i < size; i++) {
        Node* newNode = new Node(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    return head;
}

// Function to print the doubly linked list
void printDoublyLinkedList(Node* head) {
    Node* temp = head;

    // Print forward
    cout << "Forward: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Print backward
    if (head) {
        // Find the tail
        while (head->next) {
            head = head->next;
        }

        cout << "Backward: ";
        while (head) {
            cout << head->data << " ";
            head = head->prev;
        }
        cout << endl;
    }
}

// Driver code
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Convert array to doubly linked list
    Node* head = arrayToDoublyLinkedList(arr, size);

    // Print the doubly linked list
    printDoublyLinkedList(head);

    return 0;
}
