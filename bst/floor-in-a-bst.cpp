

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