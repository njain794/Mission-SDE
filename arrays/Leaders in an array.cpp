vector<int> leaders(int a[], int n)
{
    vector<int>v;
    int maxi=a[n-1];
    v.push_back(maxi);
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]>=maxi)
        {
            maxi=a[i];
            v.push_back(maxi);
        }
    }
    reverse(v.begin(),v.end());
    return v;
    // code here
}
