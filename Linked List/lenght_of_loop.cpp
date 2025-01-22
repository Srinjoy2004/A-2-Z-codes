//https://www.naukri.com/code360/problems/find-length-of-loop_8160455?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/

int lengthOfLoop(Node *head) {
    // Write your code here
     unordered_map<Node*, int> nodeMap;
     Node * temp=head;
     int timer =1;
     int value;
     while(temp!=NULL)
     {
         if(nodeMap.find(temp) != nodeMap.end())
         {
             value=nodeMap[temp];
             return timer-value;

         } else {
           nodeMap[temp] = timer;
         }
         timer++;
         temp=temp->next;
     }return 0;
}

