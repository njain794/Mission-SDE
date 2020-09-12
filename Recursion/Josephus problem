int solve(vector<int>v,int i,int k)
{
    if(v.size()==1)
    {
        return v[0];
    }
    int index=(i+k)%(v.size());
    v.erase(v.begin()+index);
    return solve(v,index,k);
}
int josephus(int n, int k)
{
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        v.push_back(i+1);
    }
    return solve(v,0,k-1);
    //Your code here
}
