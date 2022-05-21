int findLongestConseqSubseq(int arr[], int n)
{
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(mp.find(arr[i]-1)!=mp.end())
        {
            mp[arr[i]]=0;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(mp[arr[i]]==1)
        {
            int pl=1;
            int pval=arr[i];
            while(mp.find(pval+pl)!=mp.end())
            {
                pl++;
            }
            if(pl>ans)
            {
                ans=pl;
            }
        }    
    }
    return ans;
    
    **********************#######***************************************
    
    int mx=*max_element(arr,arr+n);
    int v[mx+1]={0};
    for(int i=0;i<n;i++)
    {
        v[arr[i]]=1;
    }
    int res=0;
    int ans=0;
    for(int i=0;i<=mx;i++)
    {
        if(v[i]==1)
        {
            ans++;
        }
        else
        {
            ans=0;
        }
        res=max(ans,res);
    }
    return res;
  //Your code here
}
