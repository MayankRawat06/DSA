class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) {
        // code here
        if(!root) return;
        mirror(root -> left);
        mirror(root -> right);
        Node* temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;
    }
};