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
class Solution {
    long long findMax(TreeNode* root) {
        if(!root) return LONG_MIN;
        if(!root -> right) return root -> val;
        return findMax(root -> right);
    }
    long long findMin(TreeNode* root) {
        if(!root) return LONG_MAX;
        if(!root -> left) return root -> val;
        return findMin(root -> left);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(root -> val <= findMax(root -> left) || root -> val >= findMin(root -> right)) return false;
        return isValidBST(root -> left) && isValidBST(root -> right);
    }
};