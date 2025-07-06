#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
} ;
Node * BinaryTree()
{
    int x;
    // cout<<"enter the node "<<endl;
    cin >> x;
    if (x == -1)
    {
        return NULL;
    }
    Node *temp = new Node(x);
    cout << "enter the left child of " << x << ":";
    temp->left = BinaryTree(); // created the left node
    cout << "enter the right child of " << x << ":";
    temp->right = BinaryTree(); // created the left node

    return temp;
}
int main()
{
    cout << "enter the root node" << endl;
    Node *root;
    root = BinaryTree();
    return 0;
}