class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode* dummy = new ListNode(-300);
        ListNode* tail = head, *temp = dummy;
        dummy -> next = head;
        while(tail -> next) tail = tail -> next;
        ListNode* p = tail;
        while(temp -> next && temp -> next != p) {
            if(temp -> next -> val >= x) {
                tail -> next = temp -> next;
                temp -> next = temp -> next -> next;
                tail = tail -> next;
            }
            else temp = temp -> next;
        }
        if(temp -> next && temp -> next -> val >= x) {
            tail -> next = temp -> next;
            temp -> next = temp -> next -> next;
            tail = tail -> next;
        }
        tail -> next = NULL;
        return dummy -> next;
    }
};