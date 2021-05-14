class Solution{
    public:
    
    unordered_map<string,int>dp;
    unordered_set<string>st;
    
    int solve(string s)
    {
        int n=s.size();
        if(n==0)
        {
            return 1;
        }
        
        if(dp[s]!=0)
        {
            return dp[s];
        }
        
        for(int i=1;i<=n;i++)
        {
            int flag=0;
            string temp=s.substr(0,i);
            if(st.find(temp)!=st.end())
            {
                flag=1;
            }
            if(flag==1 and solve(s.substr(i,n))==1)
            {
                return dp[s]=1;
            }
        }
        
        return dp[s]=-1;
        
    }
    // A : given string to search
    // B : vector of available strings
    
    int wordBreak(string a, vector<string> &b) 
    {
        for(auto word:b)
        {
            st.insert(word);
        }
        
        int ans=solve(a);
        if(ans==-1)
        {
            return 0;
        }
        return 1;
        //code here
    }
};
