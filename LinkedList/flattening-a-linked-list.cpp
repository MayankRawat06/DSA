

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node* merge(Node* a, Node* b) {
    Node* res = new Node(-1);
    Node* tail = res;
    Node* p = a, *q = b;
    while(p && q) {
        if(p -> data < q -> data) {
            tail -> bottom = p;
            p = p -> bottom;
        }
        else {
            tail -> bottom = q;
            q = q -> bottom;
        }
        tail = tail -> bottom;
    }
    if(p) 
        tail -> bottom = p;
    if(q) 
        tail -> bottom = q;
    return res -> bottom;
}
Node *flatten(Node *root)
{
   // Your code here
   if(!root) return root;
   Node *ahead = flatten(root -> next);
   Node *res = merge(root, ahead);
   return res;
}