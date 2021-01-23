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
