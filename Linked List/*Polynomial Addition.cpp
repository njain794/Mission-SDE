Node* addPolynomial(Node *p1, Node *p2)
{
    Node *ans=new Node(0,0);
    Node *res=ans;
    Node *l1=p1;
    Node *l2=p2;
    
    
    while(l1!=NULL and l2!=NULL)
    {
        if(l1->pow == l2->pow)
        {
            //res->next=new Node(l1->coeff+l2->coeff,l1->pow);
            //res->coeff=l1->coeff+l2->coeff;
            //res->pow=l1->pow;
            l1->coeff+=l2->coeff;
            res->next=l1;
            
            l1=l1->next;
            l2=l2->next;
            //res=res->next;
        }
        else if(l1->pow > l2->pow)
        {
            //res->next=new Node(l1->coeff,l1->pow);
            //res->coeff=l1->coeff;
            //res->pow=l1->pow;
            res->next=l1;
            
            l1=l1->next;
            //res=res->next;
        }
        else if(l1->pow < l2->pow)
        {
            //res->next=new Node(l2->coeff,l2->pow);
            //res->coeff=l2->coeff;
            //res->pow=l2->pow;
            res->next=l2;
            
            l2=l2->next;
            //res=res->next;
        }
        res=res->next;
    }
    while(l1!=NULL)
    {
        res->next=l1;
        l1=l1->next;
        res=res->next;
    }
    while(l2!=NULL)
    {
        res->next=l2;
        l2=l2->next;
        res=res->next;
    }
    return ans->next;
    //Your code here
}
