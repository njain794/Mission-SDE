string Reduced_String(long long k, string s)
{
    stack<pair<char,int>>st;
    
    for(int i=0;i<s.size();i++)
    {
        if(st.empty())
        {
            st.push(make_pair(s[i],1));
        }
        else if(st.top().first==s[i])
        {
            st.top().second++;
            if(st.top().second==k)
            {
                st.pop();
            }
        }
        else
        {
            st.push(make_pair(s[i],1));
        }
    }
    string ans="";
    while(!st.empty())
    {
        while(st.top().second--)
        {
            ans.push_back(st.top().first);
        }
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
