class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        //unordered_set<char>st;
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int n=s.size();
        int ans=INT_MIN;
        if(s.size()==0)
        {
            return 0;
        }
        
        while(j<n)
        {
            mp[s[j]]++;
            if(mp.size()==j-i+1)
            {
                ans=max(ans,j-i+1);
                j++;
            }
            else if(mp.size()<j-i+1)
            {
                while(mp.size()<j-i+1 and i<j)
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
            else
            {
                j++;
            }
        }
        return ans;
    }
};
