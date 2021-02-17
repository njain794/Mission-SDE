#define ll unsigned long long
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        if(target==0)
        {
            return 1;
        }
        ll dp[target+1];
        for(int i=0;i<=target;i++){
            dp[i] = 0;
        }
        dp[0]=1;
        int n=nums.size();
        
        for(int i=1;i<=target;i++)
        {
           for(int j=0;j<n;j++)
           {
               if(nums[j]<=i)
               {
                   dp[i]+=dp[i-nums[j]];
               }
           }
        }
        return dp[target];
    }
};
