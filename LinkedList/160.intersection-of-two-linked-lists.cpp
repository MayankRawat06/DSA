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


// alternative


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1 = headA, *t2 = headB;
        while(t1 && t2) {
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
        int countA = 0, countB = 0;
        while(t1) {
            t1 = t1 -> next;
            countA++;
        }
        while(t2) {
            t2 = t2 -> next;
            countB++;
        }
        t1 = headA, t2 = headB;
        if(countA > 0) {
            while(countA > 0) {
                t1 = t1 -> next;
                countA--;
            }
        } else {
            while(countB > 0) {
                t2 = t2 -> next;
                countB--;
            }
        }
        while(t1 && t2) {
            if(t1 == t2) return t1;
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
        return NULL;
    }
};








// short and optimal 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1 = headA, *t2 = headB;
        while(t1 != t2) {
            t1 = t1 ? t1 -> next : headB; 
            t2 = t2 ? t2 -> next : headA;
        }
        return t1;
    }
};


