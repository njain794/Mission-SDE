
/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
Node *merge(Node *a,Node *b)
{
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
        c->next=merge(a->next,b);
    }
    else
    {
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
}
Node * mergeKLists(Node *arr[], int n)
{
    Node *temp=NULL;//new Node();
    for(int i=0;i<n;i++)
    {
        temp=merge(temp,arr[i]);
    }
    return temp;
    // Your code here
}

/***************** Min Heap Sol. n.log(k) sol. *********************/

// The main function to merge given `k` sorted linked lists.
// It takes array `lists` of size `k` and generates the sorted output
Node *mergeKLists(vector<Node*> const &lists)
{
    // create an empty min-heap
    priority_queue<Node*, vector<Node*>, comp> pq;
 
    // push the first node of each list into the min-heap
    for (Node* list: lists) {
        pq.push(list);
    }
 
    // take two pointers, head and tail, where the head points to the first node
    // of the output list and tail points to its last node
    Node *head = nullptr, *last = nullptr;
 
    // run till min-heap is empty
    while (!pq.empty())
    {
        // extract the minimum node from the min-heap
        Node* min = pq.top();
        pq.pop();
 
        // add the minimum node to the output list
        if (head == nullptr) {
            head = last = min;
        }
        else {
            last->next = min;
            last = min;
        }
 
        // take the next node from the "same" list and insert it into the min-heap
        if (min->next != nullptr) {
            pq.push(min->next);
        }
    }
 
    // return head node of the merged list
    return head;
}
