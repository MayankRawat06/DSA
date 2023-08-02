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
public:
    TreeNode* helper(vector<int>& in, vector<int>& post, int is, int ie, int ps, int pe) {
        if(is > ie || ps > pe) return NULL;
        int rootval = post[pe];
        int rootIndex = 0;
        for(int i = is; i <= ie; i++) {
            if(in[i] == rootval) {
                rootIndex = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(rootval);
        int rightLen = ie - rootIndex;
        int lis, lie, lps, lpe, ris, rie, rps, rpe;
        lis = is;
        lie = rootIndex - 1;
        lps = ps;
        // lpe = rootIndex - is - 1 + ps;
        lpe = lps + lie - lis;
        ris = rootIndex + 1;
        rie = ie;
        rps = lpe + 1;
        rpe = pe - 1;
        root -> left = helper(in, post, lis, lie, lps, lpe);
        root -> right = helper(in, post, ris, rie, rps, rpe);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return helper(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};