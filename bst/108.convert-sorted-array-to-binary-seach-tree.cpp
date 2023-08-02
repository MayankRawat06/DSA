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
    TreeNode* f(int s, int e, vector<int>& v) {
        if(s > e) return NULL;
        int mid = s + (e - s) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        root -> left = f(s, mid - 1, v);
        root -> right = f(mid + 1, e, v);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& v) {
        int n = v.size();
        return f(0, n - 1, v);
    }
};