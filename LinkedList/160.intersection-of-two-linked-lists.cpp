/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int getDiff(ListNode* a, ListNode* b) {
        ListNode* p = a, *q = b;
        int len1 = 0, len2 = 0;
        while(p && q) {
            len1++;
            len2++;
            p = p -> next;
            q = q -> next;
        }
        while(p) {
            len1++;
            p = p -> next;
        }
        while(q) {
            len2++;
            q = q -> next;
        }
        return len2 - len1;
    }
public:
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        int diff = getDiff(a, b);
        if(diff < 0) {
            ListNode* temp = a;
            a = b;
            b = temp;
            diff = -diff;
        }
        // assume b to be of longer length
        ListNode *p = a, *q = b;
        while(diff--) {
            q = q -> next;
        }
        if(p == q) return p;
        while(p && q) {
            p = p -> next;
            q = q -> next;
            if(p == q) return p;
        }
        return NULL;
    }
};