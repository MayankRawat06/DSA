#include <iostream>
#include <queue>
#include <string>
#include "Node.h"
#include "BinarySearchTree.h"
using namespace std;
class hb {
    public: 
    int mi;
    int ma;
    bool isBst;
    int mHeight;
    hb() {
        mi = INT_MAX;
        ma = INT_MIN;
        isBst = true;
        mHeight = 0;
    }
};
BinaryTreeNode<int> * takeInputLevelWise() {
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1) {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1) {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}   
void printTreeLevelWise(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return;
    }
    queue<BinaryTreeNode<int> * > pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front -> data << ": ";
        if(front -> left != NULL) {
            cout << "L" << front -> left -> data << " ";
            pendingNodes.push(front -> left);
        }
        if(front -> right != NULL) {
            cout << "R" << front -> right -> data;
            pendingNodes.push(front -> right);
        }
        cout << endl;
    }
}
bool search(BinaryTreeNode<int> *root, int x) {
    if(root == NULL) {
        return false;   
    }
    if(root -> data == x) {
        return true;
    }
    if(x < root -> data) {
        return search(root -> left, x);
    }
    return search(root -> right, x);
}
void elementsInRange(BinaryTreeNode<int> *root, int x, int y) {
    if(root == NULL) {
        return;
    }
    if(root -> data > x) {
        elementsInRange(root -> left, x, y);
    }
    if(root -> data >= x && root -> data <= y) {
        cout << root -> data << " ";
    }
    elementsInRange(root -> right, x, y);
}
int findMax(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return INT_MIN;
    }
    if(root -> right == NULL) {
        return root -> data;
    }
    return findMax(root -> right);
    // return max(root -> data, max(findMax(root -> left), findMax(root -> right)));
}
int findMin(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return INT_MAX;
    }
    if(root -> left == NULL) {
        return root -> data;
    }
    return findMin(root -> left);
    // return min(root -> data, min(findMin(root -> left), findMin(root -> right)));
}
bool isBST(BinaryTreeNode<int> *root) {
    // check if the tree is BST -- O(nh)
    if(root == NULL) {
        return true;
    }
    int leftMax = findMax(root -> left);
    int rightMin = findMin(root -> right);
    if(root -> data > leftMax && root -> data <= rightMin) {
        return isBST(root -> left) && isBST(root -> right);
    }
    return false;
}
class isBSTReturn {
    public:
        bool isBST;
        int maximum;
        int minimum;
};
isBSTReturn isBST2(BinaryTreeNode<int> *root) {
    // check if the tree is BST -- O(n)
    if(root == NULL) {
        isBSTReturn r;
        r.isBST = true;
        r.maximum = INT_MIN;
        r.minimum = INT_MAX;
        return r;
    }
    isBSTReturn left = isBST2(root -> left);
    isBSTReturn right = isBST2(root -> right);
    isBSTReturn r;
    r.maximum = max(root -> data, max(left.maximum, right.maximum));
    r.minimum = min(root -> data, min(left.minimum, right.minimum));
    r.isBST = left.isBST && right.isBST && root -> data > left.maximum && root -> data <= right.minimum;
    return r;
}
bool isBST3(BinaryTreeNode<int> *root, int minimum = INT_MIN, int maximum = INT_MAX) {
    // check if the tree is BST 
    if(root == NULL) {
        return true;
    }
    if(root -> data < minimum || root -> data > maximum) {
        return false;
    }
    bool isLeftOK = isBST3(root -> left, minimum, root -> data - 1);
    bool isRightOK = isBST3(root -> right, root -> data, maximum);
    return isLeftOK && isRightOK;
}
BinaryTreeNode<int> * buildTree(int a[], int si, int ei) {
    if(si > ei) {
        return NULL;
    }
    int mid = (si + ei) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(a[mid]);
    root -> left = buildTree(a, si, mid - 1);
    root -> right = buildTree(a, mid + 1, ei);
    return root;
}
pair<Node *, Node *> BSTtoLL(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        pair<Node *, Node *> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    }
    pair <Node *, Node *> p;
    pair<Node *, Node *> left = BSTtoLL(root -> left);
    pair<Node *, Node *> right = BSTtoLL(root -> right);
    Node *leftHead = left.first;
    Node *rightHead = right.first;
    Node *leftTail = left.second;
    Node *rightTail = right.second;
    Node *rootNode = new Node(root -> data);
    if(leftTail == NULL) {
        leftHead = rootNode;
        leftTail = rootNode;
    }
    else {
        leftTail -> next = rootNode;
    }
    if(rightHead == NULL) {
        rightTail = rootNode;
    }
    rootNode -> next = rightHead;
    p.first = leftHead;
    p.second = rightTail;
    return p;
}
void printLL(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}
vector<int> * getRootToNodePath(BinaryTreeNode<int> *root, int x) {
    if(root == NULL) {
        return NULL;
    }
    if(root -> data == x) {
        vector<int> *v = new vector<int>();
        v -> push_back(root -> data);
        return v;
    }
    vector<int> *leftPath = getRootToNodePath(root -> left, x);
    if(leftPath != NULL) {
        leftPath -> push_back(root -> data);
        return leftPath;
    }
    vector<int> *rightPath = getRootToNodePath(root -> right, x);
    if(rightPath != NULL) {
        rightPath -> push_back(root -> data);
        return rightPath;
    }
    return NULL;
}
BinaryTreeNode<int> * insert(BinaryTreeNode<int> *root, int x) {
    if(root == NULL) {
        BinaryTreeNode<int> *temp = new BinaryTreeNode<int>(x);
        return temp;
    }
    if(root -> data > x) {
        root -> left = insert(root -> left, x);
    }
    else {
        root -> right = insert(root -> right, x);
    }
    return root;
}
int maximumE(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return INT_MIN;
    }
    BinaryTreeNode<int> *temp = root;
    while(temp -> right != NULL) {
        temp = temp -> right;
    }
    return temp -> data;
}
int minimumE(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return INT_MAX;
    }
    BinaryTreeNode<int> *temp = root;
    while(temp -> left != NULL) {
        temp = temp -> left;
    }
    return temp -> data;
}
BinaryTreeNode<int> * deleteE(BinaryTreeNode<int> *root, int data) {
    if(root == NULL) {
        return NULL;
    }
    if(data < root -> data) {
        root -> left = deleteE(root -> left, data);
    }
    else if(data > root -> data) {
        root -> right = deleteE(root -> right, data);
    }
    else if(data == root -> data) {
        if(root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }
        else if(root -> left == NULL) {
            BinaryTreeNode<int> *temp = root -> right;
            root -> right = NULL;
            delete root;
            return temp;
        }
        else if(root -> right == NULL) {
            BinaryTreeNode<int> *temp = root -> left;
            root -> left = NULL;
            delete root;
            return temp;
        }
        else {
            // int maximum = findMax(root -> left);
            // root -> data = maximum;
            // root -> left = deleteE(root -> left, maximum);
            int minimum = minimumE(root -> right);
            root -> data = minimum;
            root -> right = deleteE(root -> right, minimum);
        }
    }
    return root;
}
void inOrder(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return;
    }
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}
int lca(BinaryTreeNode<int>* root, int n1, int n2) {
    if(root == NULL) {
        return -1;
    }
    int rootData = root -> data;
    if(n1 == rootData || n2 == rootData) {
        return rootData;
    }
    else if(n1 < rootData && n2 < rootData) {
        int a = lca(root -> left, n1, n2);
        if(a != -1) {
            return a;
        }
        else {
            return -1;
        }
    }
    else if(n1 > rootData && n2 > rootData) {
        int b = lca(root -> right, n1, n2);
        if(b != -1) {
            return b;
        }
        else {
            return -1;
        }
    }
    else {
        int a = lca(root -> left, n1, n2);
        int b = lca(root -> right, n1, n2);
        if(a != -1 && b != -1) {
            return rootData;
        }
        else if(a != -1) {
            return a;
        }
        else if(b != -1) {
            return b;
        }
        else {
            return -1;
        }
    }

}
hb maxBSTsubHeight(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return hb();
    }
    hb hL = maxBSTsubHeight(root -> left);
    hb hR = maxBSTsubHeight(root -> right);
    hb hh;
    int rootData = root -> data;
    if(hL.isBst && hR.isBst && hL.ma < rootData && hR.mi > rootData) {
        hh.mi = min(rootData, min(hL.mi, hR.mi));
        hh.ma = max(rootData, max(hL.ma, hR.ma));
        hh.isBst = true;
        hh.mHeight = max(hL.mHeight, hR.mHeight) + 1;
    }
    else {
        hh.isBst = false;
        hh.mHeight = max(hL.mHeight, hR.mHeight);
        // hh.mi = min(hL.mi, hR.mi);
        // hh.ma = max(hL.ma, hR.ma);
    }
    return hh;
}
int maxsubBstHeight(BinaryTreeNode<int>* root) {
    return maxBSTsubHeight(root).mHeight;
}
int getSum(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }
    return root -> data + getSum(root -> left) + getSum(root -> right);
}
void replaceKeys(BinaryTreeNode<int>* root, int* total) {
    if(root == NULL) {
        return;
    }
    replaceKeys(root -> right, total); 
    *total = *total + root -> data;
    root -> data = *total;
    replaceKeys(root -> left, total);
}
void replaceKeys(BinaryTreeNode<int>* root) {
    int total = 0;
    replaceKeys(root, &total);
}
void pathSum(BinaryTreeNode<int>* root, int k, string s) {
    if(root == NULL) {
        return;
    }
    int rootData = root -> data;
    s = s + " " + to_string(rootData);
    k -= rootData;
    if(k == 0) {
        if(!root -> left && !root -> right)
        cout << s << endl;
        else 
        s.empty();
    }
    pathSum(root -> left, k, s);
    pathSum(root -> right, k, s);
}
void pathSum(BinaryTreeNode<int>* root, int k) {
    string s = "";
    pathSum(root, k, s);
}
void printAtDepthK(BinaryTreeNode<int>* root, int k) {
    if(root == NULL || k < 0) {
        return;
    }
    if(k == 0) {
        cout << root -> data << " ";
    }
    printAtDepthK(root -> left, k - 1);
    printAtDepthK(root -> right, k - 1);
}
int printAtDisK(BinaryTreeNode<int>* root, int value, int k) {
    if(root == NULL) {
        return -1;
    }
    if(root -> data == value) {
        printAtDepthK(root, k);
        return 0;
    }
    int ld = printAtDisK(root -> left, value, k); 
    if(ld != -1) {
        if(ld + 1 == k) {
            cout << root -> data << " ";
        }
        else {
            printAtDepthK(root -> right, k - ld - 2);
        }
        return ld + 1;
    }
    int rd = printAtDisK(root -> right, value, k);
    if(rd == -1) {
        return -1;
    }
    else {
        if(rd + 1 == k) {
            cout << root -> data << " ";
        }
        else {
            printAtDepthK(root -> left, k - rd - 2);
        }
        return rd + 1;
    }
    return -1;
}
int main() {
    // BinaryTreeNode<int> *root = takeInputLevelWise();
    // int n;
    // cout << "Enter the size of array" <<endl;
    // cin >> n;
    // int *a = new int[n];
    // cout << "Enter the elements of array" <<endl;
    // for(int i = 0; i < n; i++) {
    //     cin >> a[i];
    // }
    // BinaryTreeNode<int> *root = buildTree(a, 0, n - 1);
    // printTreeLevelWise(root);
    // Node *head = BSTtoLL(root).first;
    // printLL(head);
    // int x;
    // cout << "Enter element to search" << endl;
    // cin >> x;
    // if(search(root, x)) {
    //     cout << "Element found" << endl;
    // } else {
    //     cout << "Element not found" << endl;
    // }
    // int x, y;
    // cout << "Enter range" << endl;
    // cin >> x >> y;
    // elementsInRange(root, x, y);
    // cout << isBST2(root).isBST << endl;
    // cout << isBST3(root) << endl;
    // delete []a;
    // int x;
    // cout << "Enter element to search" << endl;
    // cin >> x;
    // vector<int> *v = getRootToNodePath(root, x);
    // for(int i = 0; i < v -> size() - 1; i++) {
    //     cout << v -> at(i) << " -> ";
    // }
    // cout << v -> at(v -> size() - 1) << endl;
    // delete v;
    // int x;
    // cout << "Enter element to insert" << endl;
    // cin >> x;
    // root = insert(root, x);
    // int x;
    // cout << "Enter element to delete" << endl;
    // cin >> x;
    // root = deleteE(root, x);
    // printTreeLevelWise(root);
    // inOrder(root);
    // delete root;
    // BST b;
    // b.insert(10);
    // b.insert(5);
    // b.insert(20);
    // b.insert(7);
    // b.insert(3);
    // b.insert(15);
    // b.printTree();
    // b.deleteData(10);
    // b.printTree();
    // b.deleteData(100);
    // b.printTree();
    BinaryTreeNode<int>* root = takeInputLevelWise();
    // replaceKeys(root);
    int value, k;
    cin >> value >> k;
    printTreeLevelWise(root);
    // pathSum(root, k);
    // printAtDepthK(root, k);
    printAtDisK(root, value, k);
    // int n1, n2;
    // cout << "Enter numbers" << endl;
    // cin >> n1 >> n2;
    // cout << lca(root, n1, n2);
    // cout << maxsubBstHeight(root) << endl;
    return 0;
}
// 50 30 70 20 40 60 80 -1 -1 -1 -1 -1 -1 -1 -1 