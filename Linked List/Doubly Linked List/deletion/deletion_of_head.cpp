#include <iostream>
using namespace std;

// Definition of a node in the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Function to delete the head of a doubly linked list
Node* deleteHead(Node* head) {
    if (!head) { // If the list is empty
        cout << "The list is already empty!" << endl;
        return nullptr;
    }

    Node* temp = head; // Store the current head node
    head = head->next; // Move the head pointer to the next node

    if (head) {
        head->prev = nullptr; // Update the new head's prev pointer
    }

    delete temp; // Free the memory of the old head
    return head; // Return the updated head pointer
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
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Convert array to doubly linked list
    Node* head = arrayToDoublyLinkedList(arr, size);

    cout << "Original List: ";
    printDoublyLinkedList(head);

    // Delete the head node
    head = deleteHead(head);

    cout << "After deleting the head: ";
    printDoublyLinkedList(head);

    return 0;
}
