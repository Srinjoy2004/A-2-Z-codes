// https://www.naukri.com/code360/problems/find-length-of-loop_8160455?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

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

int lengthOfLoop(Node *head)
{
    // Write your code here
    unordered_map<Node *, int> nodeMap;
    Node *temp = head;
    int timer = 1;
    int value;
    while (temp != NULL)
    {
        if (nodeMap.find(temp) != nodeMap.end())
        {
            value = nodeMap[temp];
            return timer - value;
        }
        else
        {
            nodeMap[temp] = timer;
        }
        timer++;
        temp = temp->next;
    }
    return 0;
}

// optimal using tortoise and hare

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
int findlength(Node *slow, Node *fast)
{
    fast = fast->next;
    int count = 1;
    while (slow != fast)
    {
        count++;
        fast = fast->next;
    }
    return count;
}
int lengthOfLoop(Node *head)
{
    // Write your code here

    Node *slow = head;
    Node *fast = head;
    int timer = 1;
    int value;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return findlength(slow, fast);
    }
    return 0;
}
