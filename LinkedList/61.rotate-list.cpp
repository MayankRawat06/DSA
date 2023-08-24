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
    ListNode* f(ListNode* head, int k) {
        if(!head || !head -> next || k == 0) return head;
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode *curr = head, *prev = dummy;
        while(curr -> next) {
            prev = prev -> next;
            curr = curr -> next;
        }
        curr -> next = head;
        prev -> next = NULL;
        return f(curr, k - 1);
    }
    int length(ListNode* head) {
        if(!head) return 0;
        ListNode* temp = head;
        int count = 0;
        while(temp) {
            count++;
            temp = temp -> next;
        }
        return count;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head -> next || k == 0) return head;
        int l = length(head);
        return f(head, k % l);
    }
};