#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor for creating a node with data and next pointer
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor for creating a node with data only
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to convert an array to a linked list
Node* convertarr2LL(vector<int>& arr) {
    if (arr.empty()) return nullptr; // Handle empty array case

    Node* head = new Node(arr[0]); // Create the head node
    Node* mover = head; // Pointer pointing towards head

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]); // Create a new node
        mover->next = temp; // Link the current node to the new node
        mover = mover->next; // Move to the new node
    }

    return head;
}

// Function to print the linked list
//this is basically linked list traversal
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertarr2LL(arr);

    // Print the linked list to verify
    cout << "Linked list: ";
    printLinkedList(head);

    return 0;
}
