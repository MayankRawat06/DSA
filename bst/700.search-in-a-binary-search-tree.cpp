class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;
        if(root -> val == val) return root;
        TreeNode* target = NULL;
        if(val < root -> val) target = searchBST(root -> left, val);
        else target = searchBST(root -> right, val);
        return target;
    }
};