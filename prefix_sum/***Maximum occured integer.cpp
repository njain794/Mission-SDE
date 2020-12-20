int maxOccured(int L[], int R[], int n, int maxx)
{
    return res;*/
    int arr[maxx]={0};
    for(int i=0;i<n;i++)
    {
        arr[L[i]] += 1;
        arr[R[i]+1] -=1;
    }
    int mx=arr[0];
    int idx=0;
    for(int i=1;i<maxx;i++)
    {
        arr[i]+=arr[i-1];
        if(mx<arr[i])
        {
            mx=arr[i];
            idx=i;
        }
    }
    return idx;
    // Your code here
}
