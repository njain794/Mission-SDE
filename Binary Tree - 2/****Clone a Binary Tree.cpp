Node* cloneTree(Node* tree)
{

if(!tree)
return NULL;

Node* temp = new Node(tree->data);
temp->random = tree->random;
temp->left = cloneTree(tree->left);
temp->right = cloneTree(tree->right);
return temp;
   //Your code here
}
///// This is not the correct submission to this problem , can be used for submitting in coding rounds .///////////
