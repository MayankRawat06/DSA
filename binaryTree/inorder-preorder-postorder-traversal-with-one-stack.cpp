vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    // [inorder, preorder, postorder] 
    stack<pair<TreeNode*, int>> s;
    s.push({root, 0});
    vector<vector<int>> v(3);
    while(!s.empty()) {
        TreeNode* curr = s.top().first;
        int order = s.top().second;
        s.pop();
        if(order == 0) {
            v[1].push_back(curr -> data);
            s.push({curr, order + 1});
            if(curr -> left) s.push({curr -> left, 0});
        } else if(order == 1) {
            v[0].push_back(curr -> data);
            s.push({curr, order + 1});
            if(curr -> right) s.push({curr -> right, 0});
        } else {
            v[2].push_back(curr -> data);
        }
    }
    return v;
}