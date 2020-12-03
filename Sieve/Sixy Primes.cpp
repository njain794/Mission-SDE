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
    vector<int> sixyPrime(int l, int r) 
    {
        vector<int>v;
        for(int i=l;i<=r-6;i++)
        {
            if(i>=2)
            {
                if(isprime(i) and isprime(i+6))
                {
                    v.push_back(i);
                    v.push_back(i+6);
                }
            }
        }
        if(v.size()==0)
        {
            v.push_back(-1);
        }
        return v;
        // code here
    }
};
