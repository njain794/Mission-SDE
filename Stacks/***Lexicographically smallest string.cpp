string lexicographicallySmallest(string s, int k) 
    {
        int n=s.size();
        
        if(n&(n-1))
        {
            k*=2;
        }
        else{
            k/=2;
        }
        
        if(k==0)
        {
            return s;
        }
        if(k>=n)
        {
            return "-1";
        }
        
        vector<bool>vis(n,false);
        stack<int>st;
        
        int i=1;
        st.push(0);
        while(i<n)
        {
            while(s[st.top()]>s[i] && !st.empty())
            {
                vis[st.top()]=true;
                st.pop();
                k--;
                if(k==0 or st.empty())
                {
                    break;
                }
            }
            st.push(i);
            i++;
            if(k<=0)
            {
                break;
            }
        }
        
        while(k--)
        {
            vis[st.top()]=true;
            st.pop();
        }
        
        string ans;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
