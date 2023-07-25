class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        queue<pair<Node*, int>> q;
        map<int, int> map;
        q.push({root, 0});
        while(!q.empty()) {
            Node* node = q.front().first;
            int line = q.front().second;
            q.pop();
            if(map.count(line) == 0) map[line] = node -> data;
            if(node -> left) q.push({node -> left, line - 1});
            if(node -> right) q.push({node -> right, line + 1});
        }
        vector<int> res;
        for(auto it : map) res.push_back(it.second);
        return res;
    }

};