Node *add(Node *p1, Node* p2)
{
if(p1==NULL)
return p2;
if(p2==NULL)
return p1;
if(p1->pow > p2->pow)
{
p1->next=add(p1->next,p2);
return p1;
}
else if(p1->pow < p2->pow)
{
p2->next=add(p1,p2->next);
return p2;
}
else
{
p1->coeff=p1->coeff+p2->coeff;
p1->next=add(p1->next,p2->next);
return p1;
}
}
void addPolynomial(Node *p1, Node *p2)
{
Node *cur=add(p1,p2);
cout<<cur->coeff<<"x^"<<cur->pow;
cur=cur->next;
while(cur)
{
cout<<" + "<<cur->coeff<<"x^"<<cur->pow;
cur=cur->next;
}
//cout<<endl; }="">
