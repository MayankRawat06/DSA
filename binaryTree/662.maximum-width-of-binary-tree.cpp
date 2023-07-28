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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long width = 0;
        while(!q.empty()) {
            int sz = q.size();
            long long mini = q.front().second;
            long long first = 0, last = 0;
            for(int i = 0; i < sz; i++) {
                TreeNode* node = q.front().first;
                long long id = q.front().second - mini; q.pop();
                if(i == 0) first = id;
                if(i == sz - 1) last = id;
                if(node -> left) q.push({node -> left, 2 * id + 1});
                if(node -> right) q.push({node -> right, 2 * id + 2});
            }
            width = max(width, last - first + 1);
        }
        return width;
    }
};