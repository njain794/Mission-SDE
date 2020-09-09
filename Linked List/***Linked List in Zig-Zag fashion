Node *zigZag(Node* head)
{
Node* temp=head;
Node* c=temp->next;

while(temp && c )
{
if(temp->data>c->data)
{ swap(temp->data,c->data);
}
temp=temp->next;
c=c->next;
if(c==NULL)
{
break;
}

if(temp->data<c->data)
{
swap(temp->data,c->data);
}
temp=temp->next;
c=c->next;
}
return head;
}
