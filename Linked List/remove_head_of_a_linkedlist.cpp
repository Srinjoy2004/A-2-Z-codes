#include <iostream>
using namespace std;

// Definition for singly linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to remove the head node
void removeHead(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to remove." << endl;
        return ;
    }

    Node* temp = head; // Save the current head
    head = head->next; // Move head to the next node
    free (temp);       // Free the memory of the old head
}

void printList(Node* head) {
    while (head!=nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> nullptr
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout << "Original list: ";
    printList(head);

    // Remove the head node
    removeHead(head);
    cout << "After removing head: ";
    printList(head);

    // Clean up remaining nodes
   
    return 0;
}