class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) 
    {
        vector<vector<int>> ans;
        if(in.size()==0)
        {
            return ans;
        }
        sort(in.begin(),in.end());
        
        vector<int>temp=in[0];
        
        for(auto x:in)
        {
            if(x[0]<=temp[1])
            {
                temp[1]=max(temp[1],x[1]);
            }
            else
            {
                ans.push_back(temp);
                temp=x;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
