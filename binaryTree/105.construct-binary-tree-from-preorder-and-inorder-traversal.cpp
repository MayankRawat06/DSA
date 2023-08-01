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
    TreeNode* f(vector<int>& pre, vector<int>& in, int ps, int pe, int is, int ie) {
        if(is > ie || ps > pe) return NULL;
        int lis, lie, lps, lpe, ris, rie, rps, rpe;
        TreeNode* root = new TreeNode(pre[ps]);
        int rootIndex = 0;
        for(int i = is; i <= ie; i++) {
            if(in[i] == root -> val) {
                rootIndex = i;
                break;
            }
        }
        ris = rootIndex + 1;
        rie = ie;
        lis = is;
        lie = rootIndex - 1;
        lps = ps + 1; 
        lpe = lie - lis + lps;
        rps = lpe + 1;
        rpe = pe;
        root -> left = f(pre, in, lps, lpe, lis, lie);
        root -> right = f(pre, in, rps, rpe, ris, rie);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return f(pre, in, 0, pre.size() - 1, 0, in.size() - 1);
    }
};