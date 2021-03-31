int max_sum(int arr[],int n)
{
    int ms=0;
    for(int i=0;i<n;i++)
    {
        ms+=arr[i];
    }
    int s=0;
    for(int i=0;i<n;i++)
    {
        s=s+(i*arr[i]);
    }
    int ans=s;
    for(int i=1;i<n;i++)
    {
        int temp=(s-ms)+arr[i-1]*n;
        ans=max(ans,temp);
        s=temp;
    }
    return ans;
//Your code here
}
