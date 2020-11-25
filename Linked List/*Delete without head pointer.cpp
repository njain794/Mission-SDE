void deleteNode(Node *node)
{
    int x=node->data;
    int y=node->next->data;
    
    node->data=y;
    Node *temp=node->next;
    node->next=node->next->next;
    delete temp;
    //node->next->next=node;
   // Your code here
}
