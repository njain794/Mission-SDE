class Solution{
    public:
    string Reduced_String(int k,string s)
    {
        if(k==1)
        {
            return "";
        }
        stack<pair<char,int>>st;
        
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            {
                st.push({s[i],1});
            }
            else
            {
                auto p=st.top();
                if(p.first==s[i])
                {
                    st.push({s[i],p.second+1});
                    if(p.second+1==k)
                    {
                        int g=p.second+1;
                        while(g--)
                        {
                            st.pop();
                        }
                    }
                }
                else
                {
                    st.push({s[i],1});
                }
            }
        }
        
        string ans;
        while(!st.empty())
        {
            auto p=st.top();
            ans+=p.first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        // Your code goes here
    }


};
