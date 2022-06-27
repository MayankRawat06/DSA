#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;
TreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of children of " << front -> data << endl;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int data;
            cout << "Enter data of " << i + 1 << "th children of " << front -> data << endl;
            cin >> data;
            TreeNode<int>* child = new TreeNode<int>(data);
            front -> children.push_back(child);
            pendingNodes.push(child); 
        }
    }
    return root;
}   
void printTreeLevelWise(TreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front-> data << " : ";
        for(int i = 0; i < front -> children.size(); i++) {
            cout << front -> children[i] -> data << " ";
            pendingNodes.push(front -> children[i]);
        }
        cout << endl;
    }
}
int getHeight(TreeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }
    int height = 0;
    int maxHeight = 0;
    for(int i = 0; i < root -> children.size(); i++) {
        height = getHeight(root -> children[i]);
        if(height > maxHeight) {
            maxHeight = height;
        }
    }
    return maxHeight + 1;
}
int sumNodes(TreeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }
    int sum = 0;
    for(int i = 0; i < root -> children.size(); i++) {
        sum += sumNodes(root -> children[i]);
    }
    return sum + root -> data;
}
int largestNode(TreeNode<int>* root) {
    if(root == NULL) {
        return -1;
    }
    int lData = root -> data;
    int data = 0;
    for(int i = 0; i < root -> children.size(); i++) {
        data = largestNode(root -> children[i]);
        if(data > lData) {
            lData = data;
        }
    }
    return lData;
}
void postOrder(TreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    for(int i = 0; i < root -> children.size(); i++) {
        postOrder(root -> children[i]);
    }
    cout << root -> data << " "; 
}
void getNodesAtDepthK(TreeNode<int>* root, int k) {
    if(root == NULL) {
        return;
    }
    if(k == 0) {
        cout << root -> data << " ";
    }
    else {
        for(int i = 0; i < root -> children.size(); i++) {
            getNodesAtDepthK(root -> children[i], k - 1);
        }
    }
    cout << endl;
}
int countLeafNodes(TreeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }
    int n = 0;
    if(root -> children.size() == 0) {
        return 1;
    }
    for(int i = 0; i < root -> children.size(); i++) {
        n += countLeafNodes(root -> children[i]);
    }
    return n;
}
bool isPresent(TreeNode<int>* root, int k) {
    if(root == NULL) {
        return false;
    }
    if(root -> data == k) {
        return true;
    }
    bool ans = false;
    for(int i = 0; i < root -> children.size(); i++) {
        ans = isPresent(root -> children[i], k);
    } 
    return ans;
}
int countNodes(TreeNode<int>* root, int k) {
    if(root == NULL) {
        return 0;
    }
    int count = 0;
    if(root -> data > k) {
        count++;
    }
    for(int i = 0; i < root -> children.size(); i++) {
        count += countNodes(root -> children[i], k);
    }  
    return count;
}
int maxChildSum(TreeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }
    int mNode = root -> data;
    int sum = root -> data;
    for(int i = 0; i < root -> children.size(); i++) {
        sum += root -> children[i] -> data;
    }
    int maxS = sum;
    for(int i = 0; i < root -> children.size(); i++) {
        int s = maxChildSum(root -> children[i]);
        if(s > maxS) {
            maxS = s;
        }
    }
    return maxS;
}
pair<TreeNode<int>*, int> mChildSumNode(TreeNode<int>* root) {
    pair<TreeNode<int>*, int> m;
    m.first = root;
    if(root == NULL) {
        m.second = 0;
        return m;
    }
    m.second = root -> data;
    for(int i = 0; i < root-> children.size(); i++) {
        m.second += root-> children[i] -> data;
    }
    for(int i = 0; i < root-> children.size(); i++) {
        pair<TreeNode<int>*, int> p = mChildSumNode(root-> children[i]);
        if(p.second > m.second) {
            return p;
        }
    } 
    return m;
}
bool areIdentical(TreeNode<int>* root1, TreeNode<int>* root2) {
    if(root1 == NULL && root2 == NULL) {
        return true;
    }
    else if(root1 == NULL && root2 != NULL || root2 == NULL && root1 != NULL) {
        return false;
    }
    if(root1 -> data == root2 -> data) {
        bool flag = false;
        if(root1-> children.size() == root2-> children.size())
        {
            for(int i = 0; i < root1-> children.size(); i++) {
                flag = areIdentical(root1-> children[i], root2-> children[i]);
                if(flag == false) {
                    return false;
                }
            }    
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
    return true;
}
int main() {
    TreeNode<int>* root1 = takeInput();
    printTreeLevelWise(root1);
    // cout << countLeafNodes(root) << endl;
    // postOrder(root);
    // int k;
    // cin >> k;
    // cout << countNodes(root, k) << endl;
    // cout << maxChildSum(root) << endl;
    // pair<TreeNode<int>*, int> p = mChildSumNode(root);
    // cout << p.first -> data << endl;
    // cout << p.second << endl;
    TreeNode<int>* root2 = takeInput();
    printTreeLevelWise(root2); 
    cout << areIdentical(root1, root2) << endl;
    delete root1;
    delete root2;
    return 0;
}