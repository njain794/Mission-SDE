 // Function to push element on rear of queue
void enqueue(queue<int> &s,int x)
{
    s.push(x);
   //Your code here
}
 // Function to remove front element from queue
void dequeue(queue<int> &s)
{
    if(!s.empty())
    {
        s.pop();
    }    
    //Your code here
}
 // Function to find the front element of queue
int front(queue<int> &s)
{
    if(!s.empty())
    {
        return s.front();
    }
    //Your code here
}
 // Function to find the element in queue. Return "Yes" or "No".
string find(queue<int> s, int val)
{
    string s1="Yes";
    string s2="No";
    queue<int>temp=s;
    
    while(!temp.empty())
    {
        if(temp.front()==val)
        {
            return s1;
        }
        temp.pop();
    }
    return s2;
    //Your code here
}
