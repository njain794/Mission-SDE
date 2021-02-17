string smallestK(long long n)
{
    if(n>=0 and n<=9)
    {
        return to_string(n);
    }
    
    stack<int>digits;
    
    //int i=9;
    //while(i<=2 and n>1)
    for(int i=9;i>=2 && n>1;i--)
    {
        while(n%i==0)
        {
            digits.push(i);
            n=n/i;
        }
        //i--;
    }
    
    if(n!=1)
    {
        return to_string(-1);
    }
    
    long long ans=0;
    while(!digits.empty())
    {
        ans=ans*10+digits.top();
        digits.pop();
    }
    
    return to_string(ans);
