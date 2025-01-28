//https://www.naukri.com/code360/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list_8160461?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

/**
 * Definition of doubly linked list:
 *
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
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here

    Node * temp =head;
    while(temp!=nullptr)
    {
        if(temp->data==k)
        {
            if(temp==head){
                head=temp->next;
            }
            Node *nextnode=temp->next;
            Node *prevnode=temp->prev;

            if(nextnode!=nullptr) nextnode->prev=prevnode;
            if(prevnode!=nullptr) prevnode->next=nextnode;

            delete temp;
            temp=nextnode;

        }
        else{
            temp=temp->next;
        }
    }return head;
}
