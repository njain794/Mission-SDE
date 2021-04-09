class Solution{
    
    public:
    int RulingPair(vector<int> arr, int n) 
    { 
        unordered_map<int,int>mp;
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            int res=0;
            int d=arr[i];
            while(d!=0)
            {
                res+=d%10;
                d=d/10;
            }
            if(mp.find(res)!=mp.end())
            {
                ans=max(ans,arr[i]+mp[res]);
                int g=mp[res];
                mp[res]=max(g,arr[i]);
            }
            else
            {
                mp[res]=arr[i];
            }
        }
        if(ans==INT_MIN)
        {
            return -1;
        }
        return ans;
    	// Your code goes here
    }   
};
