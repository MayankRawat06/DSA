class Solution{
    int f(Node* root) {
        if(!root) return 0;
        if(!root -> left && !root -> right) return root -> data;
        int left = f(root -> left);
        int right = f(root -> right);
        if(left == -1 || right == -1 || left + right != root -> data) 
            return -1;
        return root -> data;
    }
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
        int ans = f(root);
        return ans != -1 ? 1 : 0;
    }
};