void permute(string str,int start,int end,vector<string>&s)
{
    if(start==end)
    {
        //cout<<str<<" ";
        s.push_back(str);
        return;
    }
    for(int i=start;i<=end;i++)
    {
        swap(str[start],str[i]);
        permute(str,start+1,end,s);
        swap(str[start],str[i]);
    }
    //return;
}
void permutation(string s)
{
    int n=s.length()-1;
    vector<string>st;
    permute(s,0,n,st);
    sort(st.begin(),st.end());
    for(auto x:st)
    {
        cout<<x<<" ";
    }
    //Your code here
}
