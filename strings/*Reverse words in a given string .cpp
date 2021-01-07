string reverseWords(string s) 
{ 
    string temp;
    stack<string>st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='.')
        {
            temp.push_back(s[i]);
        }
        else
        {
            st.push(temp);
            temp.clear();
            st.push(".");
        }
    }
    st.push(temp);
    string ans;
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    return ans;
    // code here 
} 
