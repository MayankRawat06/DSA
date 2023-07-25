//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*, int>> q;
        map<int, int> map;
        q.push({root, 0});
        while(!q.empty()) {
            Node* node = q.front().first;
            int line = q.front().second;
            q.pop();
            map[line] = node -> data;
            if(node -> left) q.push({node -> left, line - 1});
            if(node -> right) q.push({node -> right, line + 1});
        }
        vector<int> res;
        for(auto it : map) {
            res.push_back(it.second);
        }
        return res;
    }
};