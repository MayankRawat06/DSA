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
    map<pair<int, int>, vector<TreeNode*>> map;
    vector<TreeNode*> f(int s, int e) {
        if(s > e) return {NULL};
        if(s == e) return map[{s, e}] = {new TreeNode(s)};
        if(map.count({s, e})) return map[{s, e}];
        vector<TreeNode*> res;
        for(int i = s; i <= e; i++) {
            auto left = f(s, i - 1);
            auto right = f(i + 1, e);
            for(auto l : left) {
                for(auto r : right) {
                    TreeNode* root = new TreeNode(i);
                    root -> left = l; 
                    root -> right = r;
                    res.push_back(root);
                }
            }
        }
        return map[{s, e}] = res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return f(1, n);
    }
};