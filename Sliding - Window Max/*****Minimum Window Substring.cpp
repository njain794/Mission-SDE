class Solution {
public:
    string minWindow(string s, string t) 
    {
        string ans="";  
        unordered_map<char,int>mp;
        
        for(int i=0;i<t.size();i++)
        {
            mp[t[i]]++;
        }
        
        int i=0;
        int j=0;
        int cnt=mp.size();
        int n=s.size();
        int len=INT_MAX;
        
        while(j<n)
        {
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                {
                    cnt--;
                }
            }
            
            while(cnt==0 and i<=j)
            {
                if(j-i+1<len)
                {
                    len=j-i+1;
                    ans=s.substr(i,j-i+1);
                }
                if(mp.find(s[i])!=mp.end())
                {
                    mp[s[i]]++;
                    if(mp[s[i]]==1)
                    {
                        cnt++;
                    }
                }
                i++;
            }
            j++;
            
        }
        if(len==INT_MAX)
        {
            return "";
        }
        return ans;
    }
};
