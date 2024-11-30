//https://leetcode.com/problems/reverse-linked-list/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;
        while (temp != nullptr) {
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp != nullptr) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};

//optimal

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

*/

Node* reverseDLL(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    
    Node* temp = NULL;
    Node* current = head;
    
    // Traverse the list and swap next and prev pointers
    while (current != NULL) {
        // Swap the next and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        // Move to the next node (which is now 'prev' because we've swapped the pointers)
        current = current->prev;
    }
    
    // After the loop, 'current' will be NULL, and the 'head' will need to point to the last node.
    // The 'head' should be the last non-null node encountered (which is now 'temp->prev')
    if (temp != NULL) {
        head = temp->prev;
    }
    
    
    return head;
}


