class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> map;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int line = q.front().second.first, level = q.front().second.second;
            q.pop();
            map[line][level].insert(node -> val);
            if(node -> left) q.push({node -> left, {line - 1, level + 1}});
            if(node -> right) q.push({node -> right, {line + 1, level + 1}});
        }
        vector<vector<int>> res;
        for(auto it : map) {
            vector<int> v;
            for(auto itr : it.second) {
                auto set = itr.second;
                v.insert(v.end(), set.begin(), set.end());
            }
            res.push_back(v);
        }
        return res;
    }
};