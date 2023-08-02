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
        if(s == e) return new TreeNode(v[s]);
        TreeNode* root = new TreeNode(v[s]);
        int lpe = e, rps = e + 1;
        for(int i = s + 1; i <= e; i++) {
            if(v[i] > root -> val) {
                rps = i;
                break;
            }
        }
        lpe = rps - 1;
        root -> left = f(s + 1, lpe, v);
        root -> right = f(rps, e, v);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& p) {
        return f(0, p.size() - 1, p);
    }
};