#include <iostream>
using namespace std;

// Definition for singly linked list
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to remove the tail node
void removetail(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is empty. Nothing to remove." << endl;
        return;
    }

    if (head->next == nullptr)
    {
        // Only one node in the list
        free(head);
        head = nullptr;
        return;
    }

    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    // Delete the tail node
    free(temp->next);
    temp->next = nullptr;
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

    // Remove the tail node
    removetail(head);
    cout << "After removing tail: ";
    printList(head);

    return 0;
}
