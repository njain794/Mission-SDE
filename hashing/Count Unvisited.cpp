int countUnvisited(int n, int m) 
{
    unordered_set<int>st;
    st.insert(0);
    st.insert(n);
    st.insert(m);
    
    int len=(n*m)-(n+m);
    int count=0;
    
    for(int i=1;i<=len;i++)
    {
        if(st.find(i-n)!=st.end())
        {
            st.insert(i);
        }
        else if(st.find(i-m)!=st.end())
        {
            st.insert(i);
        }
        else
        {
            count++;
        }
    }
    return count;
    // code here 
}
