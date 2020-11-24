/*
Structure of linked list is as
struct Node
{
	int data;
	struct Node* npx; 
	
	Node(int x){
	    data = x;
	    npx = NULL;
	}
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers 
struct Node* XOR (struct Node *a, struct Node *b)
{
	return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/


// function should insert the data to the front of the list
struct Node* insert(struct Node *head, int data)
{
    struct Node *new_node=new Node(data);
    //new_node->data=data;
    
    new_node->npx=XOR(NULL,head);
    
    if(head!=NULL)
    {
        head->npx=XOR(new_node,head->npx);
    }
    return new_node;
    //head=new_node;
	// Code here
}

vector<int> printList (struct Node *head)
{
    struct Node *prev=NULL;
    struct Node *curr=head;
    struct Node *next;
    vector<int>v;
    
    while(curr!=NULL)
    {
        v.push_back(curr->data);
        
        next=XOR(prev,curr->npx);
        prev=curr;
        curr=next;
    }
    return v;
	// Code here
}
