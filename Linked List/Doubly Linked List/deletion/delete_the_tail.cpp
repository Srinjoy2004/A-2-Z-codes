#include <iostream>
using namespace std;

// Definition of a node in the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Function to delete the tail of a doubly linked list
Node* deleteTail(Node* head) {
    if (!head) { // If the list is empty
        cout << "The list is already empty!" << endl;
        return nullptr;
    }

    if (!head->next) { // If the list has only one node
        delete head;
        return nullptr;
    }

    Node* prev = nullptr;
    Node* temp = head;

    // Traverse the list to find the tail
    while (temp->next != nullptr) {
        prev = temp;        // Move `prev` to the current node
        temp = temp->next;  // Move `temp` to the next node
    }

    // Update the second-to-last node to remove the tail
    prev->next = nullptr;

    // Free memory of the old tail
    delete temp;

    return head; // Return the updated head
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

    // Print the original list
    cout << "Original List: ";
    printDoublyLinkedList(head);

    // Delete the tail node
    head = deleteTail(head);

    // Print the updated list
    cout << "After deleting the tail: ";
    printDoublyLinkedList(head);

    return 0;
}
