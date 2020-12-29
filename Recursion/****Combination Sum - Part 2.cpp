class Solution{
    public:
    set<vector<int>>st;
    void solve(vector<int> arr,int sum,int index,vector<int>temp,vector<vector<int>>&res)
    {
        if(sum<0)
        {
            return;
        }
        if(sum==0)
        {
            if(st.find(temp)==st.end())
            {
                st.insert(temp);
                res.push_back(temp);
            }    
            return;
        }
        for(int i=index;i<arr.size();i++)
        {
            if(arr[i]<=sum)
            {
                temp.push_back(arr[i]);
                sum=sum-arr[i];
                
                solve(arr,sum,i+1,temp,res);
                sum=sum+arr[i];
                temp.pop_back();
            }
        }
        return;
        
    }
    vector<vector<int>> combinationSum(vector<int> &arr, int n, int sum)
    {
        sort(arr.begin(),arr.end());
        vector<int>temp;
        vector<vector<int>>res;
        int index=0;
        
        solve(arr,sum,index,temp,res);
        return res;
        // code here
    }
};
