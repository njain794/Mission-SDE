int trappingWater(int arr[], int n)
{
    int mxl[n+1];
    int mxr[n+1];
    //int ans[n+1];
    
    mxl[0]=arr[0];
    mxr[n-1]=arr[n-1];
    
    for(int i=1;i<n;i++)
    {
        mxl[i]=max(arr[i],mxl[i-1]);
    }
    for(int i=n-2;i>=0;i--)
    {
        mxr[i]=max(arr[i],mxr[i+1]);
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int temp=min(mxl[i],mxr[i])-arr[i];
        sum+=temp;
    }
    return sum;
    // Your code here
}
