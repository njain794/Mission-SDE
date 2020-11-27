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
Node *merge(Node *a,Node *b)
{
    if(a==NULL and b==NULL)
    {
        return a;
    }
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }
    Node *c;
    if(a->data < b->data)
    {
        c=a;
        c->bottom=merge(a->bottom,b);
    }
    else
    {
        c=b;
        c->bottom=merge(a,b->bottom);
    }
    c->next=NULL;
    return c;
}    
Node *flatten(Node *root)
{
    if(root==NULL or root->next==NULL)
    {
        return root;
    }
    
    return merge(root,flatten(root->next));
   // Your code here
}
