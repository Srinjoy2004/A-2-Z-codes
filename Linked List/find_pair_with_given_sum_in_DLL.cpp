// https://www.naukri.com/code360/problems/find-pairs-with-given-sum-in-doubly-linked-list_1164172?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/
Node *findtail(Node *head)
{
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    return tail;
}

vector<pair<int, int>> findPairs(Node *head, int k)
{
    // Write your code here.
    Node *left = head;
    Node *right = findtail(head);
    vector<pair<int, int>> ans;
    if (head == nullptr)
        return ans;
    while (left->data < right->data)
    {
        if (left->data + right->data == k)
        {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (left->data + right->data < k)
        {
            left = left->next;
        }
        else
            right = right->prev;
    }
    return ans;
}
