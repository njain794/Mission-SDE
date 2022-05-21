class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) 
    {
        unordered_map<int,int>mp;
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(k-arr[i])!=mp.end())
            {
                auto it=mp.find(k-arr[i]);
                res+=it->second;
            }
            mp[arr[i]]++;
        }
        return res;
        // code here
    }
};
