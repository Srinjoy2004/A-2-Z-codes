//https://www.naukri.com/code360/problems/remove-duplicates-from-a-sorted-doubly-linked-list_2420283?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM


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
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
    // Write your code here
    Node *temp=head;
    while(temp!=nullptr && temp->next !=nullptr)
    {
        Node * nextnode=temp->next;
    
    
    while(nextnode!=nullptr && nextnode->data==temp->data)
    {
         Node * duplicate = nextnode;
         nextnode=nextnode->next;
         delete duplicate;

    }

    temp->next=nextnode;
    if(nextnode!=nullptr)
       nextnode->prev=temp;
    temp=temp->next;
}
return head;
}
