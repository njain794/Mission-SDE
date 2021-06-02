
int trailingZeroes(int n)
    {
        int cnt=0;
        for(int i=5;(n/i)>=1;i*=5)
        {
            cnt+=n/i;
        }
        return cnt;
        // Write Your Code here
    }

/////////////////////////////////////////////////////

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int ans=0;
        int p=5;
        while((n/p)>0)
        {
            ans+=n/p;
            p=p*5;
        }
        return ans;
        // Write Your Code here
    }
};
