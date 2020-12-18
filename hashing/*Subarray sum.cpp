int solve(vector<int>v,int i,int j)
{
    int sum=0;
    for(int k=i;k<=j;k++)
    {
        sum+=v[k];
    }
    return sum;
}
int maximum_sum(vector<int>v)
{
    unordered_map<int,int>mp;
    int n=v.size();
    int ms=v[0];
    mp[v[0]]=0;
    int pfx[n];
    pfx[0]=v[0];
    for(int i=1;i<n;i++)
    {
        pfx[i]=pfx[i-1]+v[i];
    }
    
    for(int i=1;i<n;i++)
    {
        if(mp.find(v[i])!=mp.end())
        {
           int x=mp[v[i]]; 
           int sum=pfx[i]-pfx[x-1];
           ms=max(ms,sum);
        }
        else
        {
            mp[v[i]]=i;
        }
    }
    return ms;
    // Your code here
}
