//https://leetcode.com/problems/palindrome-linked-list/description/

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
    bool isPalindrome(ListNode* head) {
        vector <int> store;
        ListNode* temp=head;
        ListNode* head_store=head;
        int i=0;
        while(temp!=nullptr)
        { 
          store.push_back(temp->val);
          i++;
          temp=temp->next;
        }

        for(int j=store.size()-1;j>=0;j--)
        {
            if (store[j]!=head_store->val) return false;
            head_store=head_store->next;

        }return true;
    }
};