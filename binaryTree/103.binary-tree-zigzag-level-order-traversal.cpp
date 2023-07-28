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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool x = 0;
        while(!q.empty()) {
            int sz = q.size();
            vector<int> v(sz);
            for(int i = 0; i < sz; i++) {
                TreeNode* front = q.front();
                q.pop();
                int index;
                x == 1 ? index = sz - i - 1 : index = i;
                v[index] = front -> val;
                if(front -> left) q.push(front -> left);
                if(front -> right) q.push(front -> right);
            }
            x = !x;
            res.emplace_back(v);
        }
        return res;
    }
};