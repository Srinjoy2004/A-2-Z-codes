//https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTabValue=PROBLEM

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head){
    // Write your code here.
    Node * temp=head;
    int zero=0;
    int one=0;
    int two=0;
    while(temp!=nullptr){
        if(temp->data==1) one++;
        else if(temp->data==0) zero++;
        else if(temp->data==2) two++;

        temp=temp->next;
        
    }

    
    temp=head;
    while(zero!=0){
        temp->data=0;
        temp=temp->next;
        zero--;
    }
    while(one!=0){
        temp->data=1;
        temp=temp->next;
        one--;
    }
    while(two!=0){
        temp->data=2;
        temp=temp->next;
        two--;
    }return head;
}