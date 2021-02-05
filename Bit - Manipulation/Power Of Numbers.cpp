long long power(int n,int r)
{
    if(r==0)
    {
        return 1;
    }
    return (n*power(n,r-1))%mod;
 }   
