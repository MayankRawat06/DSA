/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class NodeValues {
public:
    int sum;
    int largest;
    int smallest;
    NodeValues(int sum, int largest, int smallest) {
        this -> sum = sum;
        this -> largest = largest;
        this -> smallest = smallest;
    }
};
class Solution {
    int res;
    NodeValues f(TreeNode* root) {
        if(!root) return NodeValues(0, INT_MIN, INT_MAX); // empty tree is a BST of sum 0
        // get values from left and right subtree
        NodeValues left = f(root -> left), right = f(root -> right);
        // curr node is greater that max in left AND lesser than minimum in right then it is a BST
        if(left.largest < root -> val && root -> val < right.smallest) {
            // if BST
            int sum = left.sum + right.sum + root -> val;
            res = max(res, sum);
            return NodeValues(sum, max(right.largest, root -> val), min(root -> val, left.smallest));
        } // if not BST return INT_MAX, INT_MIN such it can't be valid further 
        else return NodeValues(max(left.sum, right.sum), INT_MAX, INT_MIN);
    }
public:
    int maxSumBST(TreeNode* root) {
        res = 0; // NULL BST gives zero sum, better than negative sum
        f(root);
        return res;
    }
};