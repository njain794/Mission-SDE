void solve(int i,vector<int>&A,int n,vector<int>&temp,vector<vector<int>>&v,set<vector<int>>&s)
{
    if(i==n)
    {
        if(s.find(temp)==s.end())
        {
            s.insert(temp);
            v.push_back(temp);
        }    
        return;
    }
    
    temp.push_back(A[i]);
    solve(i+1,A,n,temp,v,s);
    //temp.push_back(A[i]);
    temp.pop_back();
    solve(i+1,A,n,temp,v,s);
    //temp.pop_back();
}
vector<vector<int> > AllSubsets(vector<int> A, int n)
{
    vector<vector<int>>v;
    vector<int>temp;
    set<vector<int>>s;
    
    solve(0,A,n,temp,v,s);
    sort(v.begin(),v.end());
    return v;
    // code here 
}
