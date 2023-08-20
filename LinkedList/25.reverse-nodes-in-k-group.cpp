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
    ListNode* reverse(ListNode* head) {
        ListNode *curr = head, *prev = NULL, *next = NULL;
        while(curr) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode* h = head, *temp = head;
        int count = k - 1;
        while(temp != NULL && count > 0) {
            temp = temp -> next;
            count--;
        }
        if(count == 0 && temp) {
            ListNode* ahead = temp -> next;
            temp -> next = NULL;
            h = reverse(h);
            ListNode* x = reverseKGroup(ahead, k);
            ListNode* tail = h;
            while(tail -> next) tail = tail -> next;
            tail -> next = x;
        }
        return h;
    }
};