//https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {

        if (head ==nullptr || head->next==nullptr) return head; 

        ListNode* odd = head;
        ListNode* oddhead = head;

        ListNode* even = head->next;
        ListNode* evenhead = head->next;

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            even->next = even->next->next;
            
            odd=odd->next;
            even=even->next;

        }
        odd->next = evenhead;
        return oddhead;
    }
};