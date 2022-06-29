#include <iostream>
#include<queue>
#include "TreeNode.h"
using namespace std;
class Pair
{
    public:
        TreeNode<int>* node;
        int sum;
        Pair()
        {
            this-> sum= 0;
        }
};
int maxr= 0;
void printTree(TreeNode<int>* root)
{
    //recursive print
    if(root== NULL) 
    {
        return;
    }
    cout<<root-> data<<":";
    for(int i= 0; i< root-> children.size(); i++)
    {
        cout<<root-> children[i]-> data<<" ";
    }
    cout<<endl;
    for(int i= 0; i< root-> children.size(); i++)
    {
        printTree(root-> children[i]);
    }
}
TreeNode<int>* takeInput()
{
    //recursive take input
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int n;
    cout<<"Enter number of children"<<endl;
    cin>>n;
    for(int i= 0; i< n; i++)
    {
        //TreeNode<int>* child= takeInput();
        //root->children.push_back(child);
        root-> children.push_back(takeInput());
    }
    return root;
}
TreeNode<int>* takeInputLevelWise()
{
    //iterative take input
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    TreeNode<int>* root= new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!= 0)
    {
        TreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        int n;
        cout<<"Enter number of children of "<<front-> data<<endl;
        cin>>n;
        for(int i= 0; i< n; i++)
        {
            int data;
            cout<<"Enter data of "<<i+1<<"th children"<<endl;
            cin>>data;
            TreeNode<int>* child= new TreeNode<int>(data);
            front-> children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
void printTreeLevelWise(TreeNode<int>* root)
{
    //iterative print
    if(root== NULL)
    {
        return;
    }
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!= 0)
    {
        TreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        cout<<front-> data<<":";
        for(int i= 0; i< front-> children.size(); i++)
        {
            cout<<front-> children[i]-> data<<" ";
            pendingNodes.push(front-> children[i]);
        }
        cout<<endl;
    }
}
int numNodes(TreeNode<int>* root)
{
    if(root== NULL)
    {
        return 0;
    }
    //recurively num of nodes
    int ans= 1;
    for(int i= 0; i< root-> children.size(); i++)
    {
        ans+= numNodes(root-> children[i]);
    }
    return ans;
}
int sumNodes(TreeNode<int>* root)
{
    if(root== NULL)
    {
        return 0;
    }
    //recursively sum of nodes
    int sum= root-> data;
    for(int i= 0; i< root-> children.size(); i++)
    {
        sum+= sumNodes(root-> children[i]);
    }
    return sum;
}
TreeNode<int>* maxNode(TreeNode<int>* root)
{
    if(root== NULL)
    {
        return root;
    }
    //recursively max node
    if(root-> children.size()== 0)
    {
        return root;
    }
    TreeNode<int>* max= root;
    if(root-> data< root-> children[0]-> data)
    {
        max= maxNode(root-> children[0]);
    } 
    for(int i= 1; i< root-> children.size(); i++)
    {
        if(max-> data< root-> children[i]-> data)
        {
            max= maxNode(root-> children[i]);
        }
    }
    return max;
}
int treeHeight(TreeNode<int>* root)
{
    //recursively height of tree
    if(root == NULL) 
    {
        return 0;
    }
    int maxHeight= 0;
    for(int i= 0; i< root-> children.size(); i++)
    {
        int height= treeHeight(root-> children[i]);
        if(height> maxHeight)
        {
            maxHeight= height;
        }
    }
    return maxHeight+ 1;
}
void NodeatLevelK(TreeNode<int>* root, int k)
{
    //recursively print nodes at k level
    if(root== NULL) 
    {
        return;
    }
    if(k== 0)
    {
        cout<<root-> data<<" ";
        return;
    }
    for(int i= 0; i< root-> children.size(); i++)
    {
        NodeatLevelK(root-> children[i], k- 1);
    }
}
int countLeafNodes(TreeNode<int>* root)
{
    //recursively count leaf nodes
    if(root== NULL) 
    {
        return 0;
    }
    if(root-> children.size()== 0)
    {
        return 1;
    }
    int count= 0;
    for(int i= 0; i< root-> children.size(); i++)
    {
        count+= countLeafNodes(root-> children[i]);
    }
    return count;
}
void preorder(TreeNode<int>* root)
{
    //recursively preorder
    if(root== NULL) 
    {
        return;
    }
    cout<<root-> data<<" ";
    for(int i= 0; i< root-> children.size(); i++)
    {
        preorder(root-> children[i]);
    }
}
void postorder(TreeNode<int>* root)
{
    //recursively postorder
    if(root== NULL)
    {
        return;
    }
    for(int i= 0; i< root-> children.size(); i++)
    {
        postorder(root-> children[i]);
    }
    cout<<root-> data<<" ";
}
void deleteTree(TreeNode<int>* root)
{
    //recursively delete tree
    if(root== NULL)
    {
        return;
    }
    for(int i= 0; i< root-> children.size(); i++)
    {
        deleteTree(root-> children[i]);
    }
    delete root;
}
bool isPresent(TreeNode<int>* root, int data)
{
    //recursively check if data is present
    if(root== NULL)
    {
        return false;
    }
    if(root-> data== data) return true;
    for(int i= 0; i< root-> children.size(); i++)
    {
        if(isPresent(root-> children[i], data))
        {
            return true;
        }
    }
    return false;
}
int countgreater(TreeNode<int>* root, int data)
{
    //recursively count greater than data
    if(root== NULL) return 0;
    int count= 0;
    if(root-> data> data)
    {
        count++;
    }
    for(int i= 0; i< root-> children.size(); i++)
    {
        count+= countgreater(root-> children[i], data);
    }
    return count;
}
int maxChildSum(TreeNode<int>* root, int max)
{
    //recursively return node with max sum of children
    if(root== NULL) return 0;
    maxr= root-> data;
    int sum= root-> data;
    for(int i= 0; i< root-> children.size(); i++)
    {
        sum+= root-> children[i]-> data;
    }
    int maxs= sum;
    for(int i= 0; i< root-> children.size(); i++)
    {
        int childData= root-> children[i]-> data;
        int childSum= maxChildSum(root-> children[i], max);
        if(childSum> maxs)
        {
            maxr= childData;
            maxs= childSum;
        }
    }
    return maxs;
}
bool identical(TreeNode<int>* root1, TreeNode<int>* root2)
{
    //recursively check if two trees are identical
    if(root1== NULL && root2== NULL)
    {
        return true;
    }
    if(root1== NULL || root2== NULL)
    {
        return false;
    }
    if(root1-> data!= root2-> data)
    {
        return false;
    }
    bool flag= true;
    for(int i= 0; i< root1-> children.size(); i++)
    {
        flag= identical(root1-> children[i], root2-> children[i]);
        if(flag== false)
        {
            return false;
        }
    }
    return true;
}
Pair maxChildSum(TreeNode<int>* root)
{
    //Node with max sum of children and itself
    Pair p;
    p.node= root;
    if(root== NULL)
    {
        p.sum= 0;
        return p;
    }
    for(int i=0; i< root-> children.size(); i++)
    {
        p.sum+= root-> children[i]-> data;
    }
    for(int i=0; i< root-> children.size(); i++)
    {
        Pair c= maxChildSum(root-> children[i]);
        if(c.sum> p.sum)
        {
            return c;
        }
    }
    return p;
}
TreeNode<int>* justLarger(TreeNode<int>* root, int x)
{
    //Just larger number
    if(root== NULL) return NULL;
    TreeNode<int>* larger= NULL;
    if(root-> data> x)
    {
        larger= root;
    }
    for(int i= 0; i< root-> children.size(); i++)
    {
        TreeNode<int>* temp= justLarger(root-> children[i], x);
        if(temp!= NULL && (larger== NULL || temp-> data< larger-> data))
        {
            larger= temp;
        }
    }
    return larger;
}
void replaceDepth(TreeNode<int>* root, int depth)
{
    //replace with depth
    if(root== NULL) return;
    root-> data= depth;
    for(int i= 0; i< root-> children.size(); i++)
    {
        replaceDepth(root-> children[i], depth+ 1);
    }
}
int main()
{
    TreeNode<int>* root= takeInputLevelWise();
    printTree(root);
    // replaceDepth(root, 0);
    // printTree(root);
    Pair p= maxChildSum(root);
    cout<<"Node with max sum= "<< p.node-> data<<endl;
    cout<<"Max sum= "<< p.sum<<endl;
    // int x;
    // cout<<"Enter Number"<<endl;
    // cin>>x;
    // TreeNode<int>* larger= justLarger(root, x);
    // if(larger== NULL)
    // {
    //     cout<<"No node is larger than "<< x<<endl;
    // }
    // else
    // {
    //     cout<<"Larger node= "<< larger-> data<<endl;
    // }
    // printTreeLevelWise(root);
    // cout<<numNodes(root)<<endl;
    // cout<<sumNodes(root)<<endl;
    // cout<<maxNode(root)-> data<<endl;
    // cout<<treeHeight(root)<<endl;
    // int k= 0;
    // cin>> k;
    // NodeatLevelK(root, k);
    // cout<<countLeafNodes(root)<<endl;
    // preorder(root);
    // cout<<endl;
    // postorder(root);
    // deleteTree(root);
    // int data;
    // cout<<"Enter data"<<endl;
    // cin>> data;
    // cout<<countgreater(root, data)<<endl;
    // cout<<isPresent(root, data);
    // cout<<maxChildSum(root, maxr)<<endl;
    // cout<<maxr;
    // TreeNode<int>* root1= takeInputLevelWise();
    // TreeNode<int>* root2= takeInputLevelWise();
    // cout<<identical(root1, root2)<<endl;
    delete root;
    // delete root1;
    // delete root2;
    return 0;
}