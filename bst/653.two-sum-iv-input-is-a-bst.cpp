/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> s;
    bool reverse;
    void pushAll(TreeNode* root) {
        if(!root) return;
        while(root) {
            s.push(root);
            if(!reverse) root = root -> left;
            else root = root -> right;
        }
    }
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        // reverse = true -> before 
        // reverse = false -> next;
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = s.top();
        s.pop();
        if(!reverse) pushAll(node -> right);
        else pushAll(node -> left);
        return node -> val;
    }
    
    bool hasNext() {
        if(!s.empty()) return true;
        return false;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root, 0), r(root, 1);
        int i = l.next(), j = r.next();
        while(i < j) {
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};