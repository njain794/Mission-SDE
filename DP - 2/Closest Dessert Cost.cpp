class Solution {
public:
    
    void solve(int j,int sum,vector<int>top,int target,int &res)
    {
        if(j==top.size() or sum>=target)
        {
            if(abs(target-sum)<abs(target-res) or (abs(target-sum)==abs(target-res) and sum<res)) 
            {
                res=sum;
            }
            return;
        }
        solve(j+1,sum,top,target,res);
        solve(j+1,sum+top[j],top,target,res);
        solve(j+1,sum+top[j]*2,top,target,res);
    }
    
    int closestCost(vector<int>& base, vector<int>& top, int target) 
    {
        int res=base[0];
        int n=base.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int j=0;
            solve(j,base[i],top,target,res);
        }
        return res;
    }
};
