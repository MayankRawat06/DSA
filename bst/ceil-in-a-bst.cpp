

// User function Template for C++

// Function to return the ceil of given number in BST.
int x;
void f(Node* root, int key) {
    if(!root) return;
    if(root -> data == key) {
        x = key;
        return;
    }
    if(root -> data > key) {
        x = root -> data;
        f(root -> left, key);
    }
    else f(root -> right, key);
}
int findCeil(Node* root, int key) {
    x = -1;
    f(root, key);
    return x;
    // Your code here
}

// Alternative Approach

int findCeil(Node* root, int x) {
    if (root == NULL) return -1;
    if(x > root -> data) {
        return findCeil(root -> right, x);
    } else if(x < root -> data) {
        int z = findCeil(root -> left, x);
        if(z != -1) return min(root -> data, z);
        else return root -> data;
    } else return x;
}