/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    Node* p, *s;
    void pred(Node* root, int key) {
        if(!root) return;
        if(root -> key < key) {
            p = root;
            pred(root -> right, key);
        }
        else pred(root -> left, key);
    }
    void succ(Node* root, int key) {
        if(!root) return;
        if(root -> key > key) {
            s = root;
            succ(root -> left, key);
        }
        else succ(root -> right, key);
    }
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        p = NULL, s = NULL;
        pred(root, key);
        succ(root, key);
        pre = p;
        suc = s;
    }
};


// Better Approach

class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        if(!root) return;
        if(key > root -> key) {
            pre = root;
            findPreSuc(root -> right, pre, suc, key);
        }
        else if(key < root -> key) {
            suc = root;
            findPreSuc(root -> left, pre, suc, key);
        }
        else {
            if(root -> left) {
                Node *curr = root -> left;
                // find max val in left subtree - pre
                while(curr -> right) {
                    curr = curr -> right;
                }
                pre = curr;
            }
            if(root -> right) {
                Node *curr = root -> right;
                // find min val in right subtree - suc
                while(curr -> left) {
                    curr = curr -> left;
                }
                suc = curr;
            }
        }
    }
};