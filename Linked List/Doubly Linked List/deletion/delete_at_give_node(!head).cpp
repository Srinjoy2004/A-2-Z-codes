#include <iostream>
using namespace std;

// Definition of a node in the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Function to delete a given node from the doubly linked list
void deleteNode(Node* nodeToDelete) {
    if (!nodeToDelete) { // If the node is nullptr
        cout << "The node to delete is nullptr!" << endl;
        return;
    }

    // If the node to delete is not the last node
    if (nodeToDelete->next) {
        nodeToDelete->next->prev = nodeToDelete->prev;
    }

    // If the node to delete is not the first node
    if (nodeToDelete->prev) {
        nodeToDelete->prev->next = nodeToDelete->next;
    }

    // Free the memory of the node
    delete nodeToDelete;
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

    // Suppose we want to delete the node with data 3
    Node* nodeToDelete = head->next->next;  // node with data '3'

    // Delete the node
    deleteNode(nodeToDelete);

    cout << "After deleting the node with data 3: ";
    printDoublyLinkedList(head);

    return 0;
}
