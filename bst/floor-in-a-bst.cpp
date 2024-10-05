

// Function to search a node in BST.
int z;
void f(Node* root, int x) {
    if(!root) return;
    if(root -> data == x) {
        z = root -> data;
        return;
    }
    if(root -> data < x) {
        z = root -> data;
        f(root -> right, x);
    }
    else f(root -> left, x);
}
int floor(Node* root, int x) {
    // Code here
    z = -1;
    f(root, x);
    return z;
}

// alternative solution

int floorInBST(TreeNode<int> * root, int x)
{
    // Write your code here.
    if(!root) return -1;
    if(x == root -> val) return root -> val;
    else if(x > root -> val) {
        int z = floorInBST(root -> right, x);
        return max(z, root -> val);
    } else {
        int z = floorInBST(root -> left, x);
        return z;
    }
}