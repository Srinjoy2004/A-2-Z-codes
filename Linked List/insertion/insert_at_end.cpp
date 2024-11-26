#include <iostream>
using namespace std;

// Definition for singly linked list
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert an element at the end of the linked list
void insert_at_end(Node *&head, int k)
{
    Node *new_node = new Node(k); // Create a new node

    if (head == nullptr)
    {
        // If the list is empty, make the new node the head
        head = new_node;
        return;
    }

    Node *temp = head; // Temporary pointer to traverse the list

    while (temp->next != nullptr) // Traverse to the last node
    {
        temp = temp->next;
    }

    temp->next = new_node; // Link the last node to the new node
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main()
{
    // Creating a sample linked list: 1 -> 2 -> 3 -> nullptr
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout << "Original list: ";
    printList(head);

    // Insert a new element at the end
    insert_at_end(head, 108);
    cout << "After inserting at the end: ";
    printList(head);

    return 0;
}
