vector<int> remove_special_consecutive(vector<int>v,int x,int y)
{
    stack<int>st;
    vector<int>ans;
    int n=v.size();
    
    st.push(v[0]);
    ans.push_back(v[0]);
    for(int i=1;i<n;i++)
    {
        if(v[i]==x or v[i]==y)
        {
            if(!st.empty() and st.top()==v[i])
            {
                st.pop();
                ans.pop_back();
            }
            else
            {
                st.push(v[i]);
                ans.push_back(v[i]);
            }
        }
        else
        {
            st.push(v[i]);
            ans.push_back(v[i]);
        }
    }
    return ans;
