class Solution {
public:
    int singleNumber(vector<int>& arr) 
    {
        int n=arr.size();
        int ans=0;
        
        int x,sum;
        for(int i=0;i<32;i++)
        {
            x=1<<i;
            sum=0;
            for(int j=0;j<n;j++)
            {
                if(arr[j]&x)
                {
                    sum++;
                }
            }
            if(sum%3!=0)
            {
                ans|=x;
            }
        }
        return ans;
    }
};
