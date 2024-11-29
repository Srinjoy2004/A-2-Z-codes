#include <iostream>
using namespace std;

// Definition for singly linked list
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to remove node with a particular value
Node *delete_node_of_particular_value(Node *head, int k)
{
    if (head == nullptr)
        return head;
    if (k == head->data)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int count = 0;
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        count++;
        if (temp->data == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
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
    Node *head = new Node(4);
    head->next = new Node(1);
    head->next->next = new Node(10);

    cout << "Original list: ";
    printList(head);

    // Remove the tail node
    head=delete_node_of_particular_value(head,101);
    cout << "After removing tail: ";
    printList(head);

    return 0;
}
