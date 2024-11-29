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
Node *insert_at_head(Node *head, int k)
{
    //Node *temp;
    Node *temp = new Node(k);
    temp->data = k;
    temp->next = head;
    head = temp;
    return head;
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
    head = insert_at_head(head, 108);
    cout << "After inserting at head ";
    printList(head);

    return 0;
}
