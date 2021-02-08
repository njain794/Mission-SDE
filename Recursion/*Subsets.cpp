/*void solve(int i,vector<int>&A,int n,vector<int>&temp,vector<vector<int>>&v,set<vector<int>>&s)
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
}*/
void tolve(vector<int>&a,int i,vector<int>&temp,set<vector<int>>&s,vector<vector<int>>&v)
{
    if(i==a.size())
    {
        if(s.find(temp)==s.end())
        {
            s.insert(temp);
            v.push_back(temp);
        }    
        return;
    }
    temp.push_back(a[i]);
    tolve(a,i+1,temp,s,v);
    temp.pop_back();
    tolve(a,i+1,temp,s,v);
}
vector<vector<int> > AllSubsets(vector<int> A, int n)
{
    vector<vector<int>>v;
    vector<int>temp;
    set<vector<int>>s;
    
    tolve(A,0,temp,s,v);
    //solve(0,A,n,temp,v,s);
    reverse(v.begin(),v.end());
    //sort(v.begin(),v.end());
    return v;
    // code here 
}
