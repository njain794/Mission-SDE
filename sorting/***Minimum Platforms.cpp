int findPlatform(int arr[], int dep[], int n)
{
    sort(arr,arr+n);
    sort(dep,dep+n);
    
    int i=1;
    int j=0;
    int currp=1;
    int maxp=1;
    while(i<n and j<n)
    {
        if(arr[i]<=dep[j])
        {
            currp++;
            i++;
            maxp=max(maxp,currp);
        }
        else
        {
            currp--;
            j++;
        }
    }
    return maxp;
	// Your code here
	/*multimap<int,char>mp;
    char ch1='a';
    char ch2='d';
    for(int i=0;i<n;i++)
    {
        //mp[arr[i]]=ch1;
        //mp[dep[i]]=ch2;
        mp.insert({arr[i],ch1});
        mp.insert({dep[i],ch2});
    }
    int ans=0;
    int res=INT_MIN;
    for(auto x:mp)
    {
        if(x.second==ch1)
        {
            ans++;
        }
        else //if(x.second==ch2)
        {
            ans--;
        }
        res=max(res,ans);
    }
    return res;*/
}
