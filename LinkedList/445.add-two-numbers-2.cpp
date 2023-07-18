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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode* temp1 = l1;
        while(temp1 != NULL) {
            s1.push(temp1->val);
            temp1 = temp1 -> next;
        }
        ListNode* temp2 = l2;
        while(temp2 != NULL) {
            s2.push(temp2 -> val);
            temp2 = temp2 -> next;
        }
        ListNode* dummy = new ListNode(0);
        while(!s1.empty() && !s2.empty()) {
            int a = s1.top(), b = s2.top();
            s1.pop(); s2.pop();
            int sum = a + b;
            ListNode* temp = NULL;
            if(sum > 9) {
                if(!s1.empty()) s1.top() = s1.top() + sum / 10;
                else s1.push(sum / 10);
                temp = new ListNode(sum % 10);
            }
            else {
                temp = new ListNode(sum);
            }
            temp -> next = dummy -> next;
            dummy -> next = temp;
        }
        while(!s1.empty()) {
            int sum = s1.top(); s1.pop();
            ListNode* temp = NULL;
            if(sum > 9) {
                if(!s1.empty()) s1.top() = s1.top() + sum / 10;
                else s1.push(sum / 10);
                temp = new ListNode(sum % 10);
            }
            else {
                temp = new ListNode(sum);
            }
            temp -> next = dummy -> next;
            dummy -> next = temp;
        }
        while(!s2.empty()) {
            int sum = s2.top(); s2.pop();
            ListNode* temp = NULL;
            if(sum > 9) {
                if(!s2.empty()) s2.top() = s2.top() + sum / 10;
                else s2.push(sum / 10);
                temp = new ListNode(sum % 10);
            }
            else {
                temp = new ListNode(sum);
            }
            temp -> next = dummy -> next;
            dummy -> next = temp;
        }
        return dummy -> next;
    }
};