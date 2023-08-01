/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    vector<int> path;
    // vector<int> rnodes;
    void lefts(Node* root) {
        if(!root || (!root -> left && !root -> right)) return;
        path.push_back(root -> data);
        if(root -> left) lefts(root -> left);
        else lefts(root -> right);
    }
    void leafs(Node* root) {
        if(!root) return;
        if(!root -> left && !root -> right) {
            path.push_back(root -> data);
            return;
        }
        leafs(root -> left);
        leafs(root -> right);
    }
    void rights(Node* root) {
        if(!root || (!root -> left && !root -> right)) return;
        path.push_back(root -> data);
        if(root -> right) rights(root -> right);
        else rights(root -> left);
    }
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        if(!root) return path;
        path.push_back(root -> data);
        lefts(root -> left);
        leafs(root -> left);
        leafs(root -> right);
        int i = path.size();
        rights(root -> right);
        reverse(path.begin() + i, path.end());
        return path;
    }
};