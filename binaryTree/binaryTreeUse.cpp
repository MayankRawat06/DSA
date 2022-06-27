#include <iostream>
#include <queue>
#include <unordered_map>
#include "binaryTreeNode.h"
using namespace std;
class Node {
    public:
    BinaryTreeNode<int>* data;
    Node *next;
    Node(BinaryTreeNode<int>* d) {
        data = d;
        next = NULL;
    }
    ~Node() {
        delete next;
    }
};
BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data : ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}
BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ": ";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data << " ";
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}
void printTreeLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ": ";
        if (front->left != NULL)
        {
            cout << "L " << front->left->data << " ";
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R " << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
}
int numNodes(BinaryTreeNode<int> *root)
{
    // number of nodes
    if (root == NULL)
    {
        return 0;
    }
    return 1 + numNodes(root->left) + numNodes(root->right);
}
bool isPresent(BinaryTreeNode<int> *root, int x)
{
    // check if x is present
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    return isPresent(root->left, x) || isPresent(root->right, x);
}
int treeHeight(BinaryTreeNode<int> *root)
{
    // height of empty tree is 0
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(treeHeight(root->left), treeHeight(root->right));
}
void mirrorTree(BinaryTreeNode<int> *root)
{
    // mirror the tree
    if (root == NULL)
    {
        return;
    }
    swap(root->left, root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
}
void inOrder(BinaryTreeNode<int> *root)
{
    // print left, then root, then right
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void preOrder(BinaryTreeNode<int> *root)
{
    // print root, then left, then right
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(BinaryTreeNode<int> *root)
{
    // print left, then right, then root
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
BinaryTreeNode<int> *buildTreeHelper(int *preOrder, int *inOrder, int preOrderStart, int preOrderEnd, int inOrderStart, int inOrderEnd)
{
    // build a tree from preOrder and inOrder
    if (preOrderStart > preOrderEnd || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    int rootData = preOrder[preOrderStart];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    int rootIndex = -1;
    for (int i = inOrderStart; i <= inOrderEnd; i++)
    {
        if (inOrder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }
    int lInS = inOrderStart;
    int lInE = rootIndex - 1;
    int lPreS = preOrderStart + 1;
    int lPreE = lInE - lInS + lPreS;
    int rInS = rootIndex + 1;
    int rInE = inOrderEnd;
    int rPreE = preOrderEnd;
    int rPreS = lPreE + 1;
    root->left = buildTreeHelper(preOrder, inOrder, lPreS, lPreE, lInS, lInE);
    root->right = buildTreeHelper(preOrder, inOrder, rPreS, rPreE, rInS, rInE);
    return root;
}
BinaryTreeNode<int> *buildTree(int *inOrder, int *preOrder, int size)
{
    // build a tree from preorder and inOrder
    return buildTreeHelper(preOrder, inOrder, 0, size - 1, 0, size - 1);
}
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
int diameter(BinaryTreeNode<int> *root)
{
    // diameter of the tree
    if (root == NULL)
    {
        return 0;
    }
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1, max(option2, option3));
}
pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    // height and diameter of the tree
    if (root == NULL)
    {
        return make_pair(0, 0);
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int lh = leftAns.first;
    int rh = rightAns.first;
    int ld = leftAns.second;
    int rd = rightAns.second;
    int height = 1 + max(lh, rh);
    int diameter = max(ld, max(rd, lh + rh));
    return make_pair(height, diameter);
}
pair<int, int> minMax(BinaryTreeNode<int> *root)
{
    // min and max of the tree
    if (root == NULL)
    {
        return make_pair(INT_MAX, INT_MIN);
    }
    pair<int, int> leftAns = minMax(root->left);
    pair<int, int> rightAns = minMax(root->right);
    int lMin = leftAns.first;
    int lMax = leftAns.second;
    int rMin = rightAns.first;
    int rMax = rightAns.second;
    int minData = min(root->data, min(lMin, rMin));
    int maxData = max(root->data, max(lMax, rMax));
    // if(root -> left == NULL) {
    //     minData = min(minData, root -> data);
    //     maxData = max(maxData, root -> data);
    // }
    // if(root -> right == NULL) {
    //     minData = min(minData, root -> data);
    //     maxData = max(maxData, root -> data);
    // }
    return make_pair(minData, maxData);
}
BinaryTreeNode<int> *createInsertDuplicate(BinaryTreeNode<int> *root)
{
    // create a tree with duplicate nodes
    if (root == NULL) {
        return NULL;
    }
    root->left = createInsertDuplicate(root->left);
    root->right = createInsertDuplicate(root->right);
    BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int> *leftC = root->left;
    root->left = newNode;
    newNode->left = leftC;
    return root;
}
BinaryTreeNode<int> *buildTreeHelperPostIn(int *postOrder, int *inOrder, int postOrderStart, int postOrderEnd, int inOrderStart, int inOrderEnd)
{
    if (postOrderStart > postOrderEnd || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postOrder[postOrderEnd]);
    int rootIndex = 0;
    for (int i = inOrderStart; i <= inOrderEnd; i++)
    {
        if (inOrder[i] == root->data)
        {
            rootIndex = i;
        }
    }
    int lPS = postOrderStart;
    int lIS = inOrderStart;
    int lIE = rootIndex - 1;
    int lPE = lIE - lIS + lPS;
    int rPS = lPE + 1;
    int rPE = postOrderEnd - 1;
    int rIS = rootIndex + 1;
    int rIE = inOrderEnd;
    root->left = buildTreeHelperPostIn(postOrder, inOrder, lPS, lPE, lIS, lIE);
    root->right = buildTreeHelperPostIn(postOrder, inOrder, rPS, rPE, rIS, rIE);
    return root;
}
BinaryTreeNode<int> *buildTreePostIn(int *postOrder, int *inOrder, int size)
{
    return buildTreeHelperPostIn(postOrder, inOrder, 0, size - 1, 0, size - 1);
}
int sumNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}
bool checkBalance(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    bool smallFlagL = checkBalance(root->left);
    bool smallFlagR = checkBalance(root->right);
    if (smallFlagL && smallFlagR && (abs(treeHeight(root->left) - treeHeight(root->right)) <= 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}
pair<bool, int> checkBalanceHelper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return make_pair(true, 0);
    }
    pair<bool, int> ansL, ansR;
    ansL = checkBalanceHelper(root->left);
    ansR = checkBalanceHelper(root->right);
    int heightc = max(ansL.second, ansR.second) + 1;
    if (ansL.first && ansR.first && (abs(ansL.second - ansR.second) <= 1))
    {
        return make_pair(true, heightc);
    }
    else
        return make_pair(false, heightc);
}
bool checkBalance1(BinaryTreeNode<int> *root)
{
    return checkBalanceHelper(root).first;
}
void printLevelOrder(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        if(front == NULL) {
            cout << endl;
            pendingNodes.pop();
            if(pendingNodes.empty()) 
                break;
            pendingNodes.push(NULL);
            continue;
        }
        cout << front->data << " ";
        pendingNodes.pop();
        if (front->left != NULL) {
            pendingNodes.push(front->left);
        }
        if (front->right != NULL) {
            pendingNodes.push(front->right);
        }
    }
}
BinaryTreeNode<int> *deleteLeaf(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return NULL;
    }
    if(!root -> left && !root -> right) {
        delete root;
        return NULL;
    }
    else {
        if(root -> left) {
            root -> left = deleteLeaf(root -> left);
        }
        if(root -> right) {
            root -> right = deleteLeaf(root -> right);
        }
    }
    return root;
}
void printLL(Node* head) {
    if(head == NULL) {
        return;
    }
    Node* temp = head;
    while(temp!= NULL) {
        cout << temp -> data -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
vector<Node*> levelOrderLL(BinaryTreeNode<int>* root) {
    vector<Node*> res;
    if (root == NULL) {
        return res;
    }
    
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    Node *head = NULL;
    Node *tail = NULL;
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        if(front == NULL) {
            res.push_back(head);
            head = NULL;
            tail = NULL;
            pendingNodes.pop();
            if(pendingNodes.empty()) 
                break;
            pendingNodes.push(NULL);
            continue;
        }
        Node* newNode = new Node(front);
        if(head == NULL || tail == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail -> next = newNode;
            tail = newNode;
        }
        pendingNodes.pop();
        if (front->left != NULL) {
            pendingNodes.push(front->left);
        }
        if (front->right != NULL) {
            pendingNodes.push(front->right);
        }
    }
    for(int i = 0; i < res.size(); i++) {
        printLL(res[i]);
    }
    return res;
}
void zigZagTree(BinaryTreeNode<int>* root) {
    vector<vector<int>> res;
    if(root == NULL) {
        return;
    }
    queue<BinaryTreeNode<int>*> qNodes;
    qNodes.push(root);
    bool flag = true;
    while(!qNodes.empty()) {
        int size = qNodes.size();
        vector<int> v(size);
        for(int i = 0; i < size; i++) {
            BinaryTreeNode<int>* front = qNodes.front();
            qNodes.pop();
            int index = (flag) ? i : (size - 1 - i);
            v[index] = front -> data;
            if(front -> left) {
                qNodes.push(front -> left);
            }
            if(front -> right) {
                qNodes.push(front -> right);
            }
        }
        flag = !flag;
        res.push_back(v);
    }
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
void noSibling(BinaryTreeNode<int>* root) {
    vector<int> v;
    if(root == NULL) {
        return;
    }
    queue<BinaryTreeNode<int>*> qNodes;
    qNodes.push(root);
    while(!qNodes.empty()) {
        BinaryTreeNode<int>* front = qNodes.front();
        qNodes.pop();
        if(front -> left && front -> right == NULL) {
            v.push_back(front -> left -> data);
        }
        if(front -> right && front -> left == NULL) {
            v.push_back(front -> right -> data);
        }
        if(front -> left) {
            qNodes.push(front -> left);
        }
        if(front -> right) {
            qNodes.push(front -> right);
        }
    }
    for(auto i : v) {
        cout << i << " ";
    }
}
void pairSum(BinaryTreeNode<int>* root, BinaryTreeNode<int>* co, int x) {
    if(root == NULL) {
        return;
    }
    int rootData = root -> data;
    int rem = x - rootData;
    if(root -> data != INT_MIN) {
        if(isPresent(co, rem)) {
            cout << rootData << " " << rem << endl;
            root -> data = INT_MIN;
        }
    }
    pairSum(root -> left, co, x);
    pairSum(root -> right, co, x);
}
void putIntoVector(BinaryTreeNode<int>* root, vector<int>& v) {
    if(root == NULL) {
        return;
    }
    putIntoVector(root -> left, v);
    v.push_back(root -> data);
    putIntoVector(root -> right, v);
}
void pairSum2(BinaryTreeNode<int>* root, int x) {
    if(root == NULL) {
        return;
    }
    vector<int> v;
    putIntoVector(root, v);
    sort(v.begin(), v.end());
    int i = 0;
    int j = v.size() - 1;
    while(i != j && i < j) {
        int sum = v[i] + v[j];
        if(sum < x) {
            i++;
        }
        else if(sum > x) {
            j--;
        }
        else {
            cout << v[i] << " " << v[j] << endl;
            i++;
            j--;
        }
    }
}
int lca(BinaryTreeNode<int>* root, int n1, int n2) {
    if(root == NULL) {
        return -1;
    }
    int rootData = root -> data;
    if(n1 == rootData || n2 == rootData) {
        return rootData;
    }
    int a = lca(root -> left, n1, n2);
    int b = lca(root -> right, n1, n2);
    if(a != -1 && b == -1) {
        return a;
    }
    else if(b != -1 && a == -1) {
        return b;
    }
    else if(a == -1 && b == -1) {
        return -1;
    }
    else {
        return rootData;
    }
}
int main()
{
    // BinaryTreeNode<int> *root = takeInput();
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int n1, n2;
    cout << "enter the numbers" << endl;
    cin >> n1 >> n2;
    cout << lca(root, n1, n2) << endl;
    // printTree(root);
    // printTreeLevelWise(root);
    // printLevelOrder(root);
    // levelOrderLL(root);
    // zigZagTree(root);
    // noSibling(root);
    // cout << "Enter x" << endl;
    // int x;
    // cin >> x;
    // pairSum(root, root, x);
    // pairSum2(root, x);
    // pair<int, int> ans = heightDiameter(root);
    // cout << "Height: " << ans.first << endl;
    // cout << "Diameter: " << ans.second << endl;
    // pair<int, int> ans = minMax(root);
    // cout << "Min: " << ans.first << endl;
    // cout << "Max: " << ans.second << endl;
    // cout << "Number of nodes: " << numNodes(root) << endl;
    // int x;
    // cout << "Enter data to search: ";
    // cin >> x;
    // cout << isPresent(root, x) << endl;
    // cout << "Height of tree: " << treeHeight(root) << endl;
    // mirrorTree(root);
    // inOrder(root);
    // cout << endl;
    // preOrder(root);
    // cout << endl;
    // postOrder(root);
    // cout << endl;
    // int n;
    // cout << "Enter number of nodes: ";
    // cin >> n;
    // int *inOrder = new int[n];
    // int *postOrder = new int[n];
    // cout << "Enter postOrder: ";
    // for(int i = 0; i < n; i++) {
    //     cin >> postOrder[i];
    // }
    // cout << "Enter inOrder: ";
    // for(int i = 0; i < n; i++) {
    //     cin >> inOrder[i];
    // BinaryTreeNode<int> *root = buildTreePostIn(postOrder, inOrder, n);
    // createInsertDuplicate(root);
    // printTreeLevelWise(root);
    // cout << checkBalance1(root) << endl;
    // deleteLeaf(root);
    delete root;
    return 0;
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1