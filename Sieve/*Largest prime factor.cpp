class Solution{
public: 
    long long int largestPrimeFactor(int n)
    {
        long long int prime[n+1]={0};
        for(int i=2;i<=n;i++)
        {
            prime[i]=i;
        }
        
        for(int i=2;i<=n;i++)
        {
            if(prime[i]==i)
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    prime[j]=i;
                }
            }
        }
        
        long long int ans=1;
        while(n!=1)
        {
            ans=max(ans,prime[n]);
            n=n/prime[n];
        }
        return ans;
        // code here
    }
};
