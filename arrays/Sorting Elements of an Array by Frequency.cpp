bool sortbysec(const pair<int,int>a,const pair<int,int>b)
{
    if(a.second!=b.second)
    {
        return (a.second>b.second);
    }
    else
    {
        return (a.first<b.first);
    }
}
vector<int> sortByFreq(int arr[],int n)
{
    map<int,int>mp;
    vector<pair<int,int>>v;
    vector<int>ans;
    
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        v.push_back(make_pair(it->first,it->second));
    }
    sort(v.begin(),v.end(),sortbysec);
    for(auto it=v.begin();it!=v.end();it++)
    {
        int k=it->second;
        while(k--)
        {
            ans.push_back(it->first);
        }
    }
    return ans;
    //Your code here
}
