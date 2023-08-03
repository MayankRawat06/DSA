/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    int k;
    int res;
    void f(Node* root) {
        if(!root) return;
        f(root -> left);
        k--;
        if(k == 0) {
            res = root -> data;
            return;
        }
        f(root -> right);
    }
    int count(Node* root) {
        if(!root) return 0;
        return 1 + count(root -> left) + count(root -> right);
    }
    public:
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int n = count(root);
        k = n - K + 1;
        f(root);
        return res;
    }
};