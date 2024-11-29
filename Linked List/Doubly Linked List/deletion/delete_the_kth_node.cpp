#include <iostream>
using namespace std;

// Definition of a node in the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Function to delete the Kth node of a doubly linked list
Node* deleteKthNode(Node* head, int K) {
    if (!head) { // If the list is empty
        cout << "The list is already empty!" << endl;
        return nullptr;
    }

    Node* temp = head;
    int count = 1;

    // Traverse the list to find the Kth node
    while (temp != nullptr && count < K) {
        temp = temp->next;
        count++;
    }

    // If K is out of bounds (greater than the length of the list)
    if (!temp) {
        cout << "K is out of bounds!" << endl;
        return head;
    }

    // If deleting the head node
    if (temp == head) {
        head = head->next; // Update head to the next node
        if (head) {
            head->prev = nullptr; // Set the previous pointer of the new head to nullptr
        }
        delete temp; // Free memory of the old head
        return head;
    }

    // If deleting a middle or tail node
    if (temp->prev) {
        temp->prev->next = temp->next; // Update the previous node's next pointer
    }
    if (temp->next) {
        temp->next->prev = temp->prev; // Update the next node's previous pointer
    }

    delete temp; // Free memory of the Kth node

    return head;
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

    int K;
    cout << "Enter the position (K) to delete: ";
    cin >> K;

    // Delete the Kth node
    head = deleteKthNode(head, K);

    cout << "After deleting the Kth node: ";
    printDoublyLinkedList(head);

    return 0;
}
