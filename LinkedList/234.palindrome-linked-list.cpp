class Solution {
    ListNode* reverse(ListNode* head) {
        ListNode *curr = head, *prev = NULL;
        while(curr) {
            ListNode *next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode *slow = dummy, *fast = head;
        while(fast && fast -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        ListNode *h = slow -> next;
        slow -> next = NULL;
        h = reverse(h);
        ListNode *t1 = head, *t2 = h;
        while(t1 && t2) {
            if(t1 -> val != t2 -> val) return false;
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
        return true;
    }
};