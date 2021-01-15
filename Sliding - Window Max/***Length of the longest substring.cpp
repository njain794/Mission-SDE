class Solution{
    public:
    int longestUniqueSubsttr(string s)
    {
        int n=s.size();
        int i=0,j=0;
        int res=INT_MIN;
        unordered_map<char,int>mp;
        while(j<n)
        {
            mp[s[j]]++;
            if(mp.size()==j-i+1)
            {
                res=max(res,j-i+1);
                j++;
            }
            else if(mp.size()<j-i+1)
            {
                while(mp.size()<j-i+1)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        if(res==INT_MIN)
        {
            return -1;
        }
        return res;
        //code
        
    }
};
