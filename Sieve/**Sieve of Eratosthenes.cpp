//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        int prime[n+1]={0};
        vector<int>res;
        
        for(int i=2;i<=n;i++)
        {
            if(prime[i]==0)
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    prime[j]=1;
                }
            }
        }
        
        for(int i=2;i<=n;i++)
        {
            if(prime[i]==0)
            {
                res.push_back(i);
            }
        }
        return res;
        // Write Your Code here
    }
};
