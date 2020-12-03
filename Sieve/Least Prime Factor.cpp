class Solution {
  public:
    bool isprime(int t)
    {
        int prime[t+1]={0};
        for(int i=2;i<=t;i++)
        {
            if(prime[t]==0)
            {
                for(int j=i*i;j<=t;j+=i)
                {
                    prime[j]=1;
                }
            }
        }
        
        if(prime[t]==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int solve(int n)
    {
        int prime[n+1]={0};
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
        int temp=n;
        while(n!=1)
        {
            temp=min(temp,prime[n]);
            n=n/prime[n];
        }
        return temp;
    }
    vector<int> leastPrimeFactor(int n) 
    {
        vector<int>v;
        v.push_back(0);
        for(int i=1;i<=n;i++)
        {
            if(i==1)
            {
                v.push_back(i);
            }
            else if(i%2==0)
            {
                v.push_back(2);
            }
            else
            {
                if(isprime(i))
                {
                    v.push_back(i);
                }
                else
                {
                    int d=solve(i);
                    v.push_back(d);
                }
            }
        }
        return v;
        
        // code here
    }
};
