//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    int lengthLinkedList(ListNode* head) {
        int l = 0;

        while (head) {
            l++;
            head = head->next;
        }
        return l;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int L = lengthLinkedList(head);
        if (n == L)
            return head->next;
        ListNode* temp = head;
       
        ListNode* previous;
        for (int i = 0; i < L - n-1; i++) {
            
            temp = temp->next;
        }
        ListNode* waste = temp->next;
        temp->next = temp->next->next;
        delete waste;
        return head;
    }
};