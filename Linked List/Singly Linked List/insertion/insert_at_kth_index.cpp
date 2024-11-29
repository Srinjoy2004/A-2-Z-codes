#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert at the Kth position
void insertAtK(Node*& head, int data, int k) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (k == 1) {
        // Inserting at the head
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < k - 1; ++i) {
        if (temp == nullptr) {
            cout << "Position out of range." << endl;
            return;
        }
        temp = temp->next;
    }

    // Insert the new node
    newNode->next = temp->next;
    temp->next = newNode;
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

    // Example insertion
    insertAtK(head, 10, 1); // Insert 10 at position 1
    insertAtK(head, 20, 2); // Insert 20 at position 2
    insertAtK(head, 15, 3); // Insert 15 at position 3
    insertAtK(head, 5, 2);  // Insert 5 at position 1

    // Print the list
    printList(head);

    return 0;
}
