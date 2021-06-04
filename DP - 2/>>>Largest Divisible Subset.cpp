class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        vector<int>ans;
        vector<int>dp;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            dp.push_back(1);
        }
        
        int mx=1;
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]%nums[j]==0 and dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    mx=max(mx,dp[i]);
                }
            }
        }
        
        int prev=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(dp[i]==mx and (prev==-1 or prev%nums[i]==0))
            {
                ans.push_back(nums[i]);
                mx-=1;
                prev=nums[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
