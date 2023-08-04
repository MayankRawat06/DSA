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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(h1 && h2) {
            if(h1 -> val < h2 -> val) {
                tail -> next = h1;
                h1 = h1 -> next;
            }
            else {
                tail -> next = h2;
                h2 = h2 -> next;
            }
            tail = tail -> next;
        }
        while(h1) {
            tail -> next = h1;
            h1 = h1 -> next;
            tail = tail -> next;
        }
         while(h2) {
            tail -> next = h2;
            h2 = h2 -> next;
            tail = tail -> next;
        }
        return dummy -> next;
    }
};