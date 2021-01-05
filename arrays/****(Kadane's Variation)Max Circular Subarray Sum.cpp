int kadane(int brr[],int n)
{
    int mxfr=brr[0];
    int res=brr[0];
    for(int i=1;i<n;i++)
    {
        mxfr+=brr[i];
        if(mxfr<brr[i])
        {
            mxfr=brr[i];
        }
        if(mxfr>res)
        {
            res=mxfr;
        }
    }
    return res;
}
int circularSubarraySum(int arr[], int num)
{
    int x=kadane(arr,num);
    int sum=0;
    for(int i=0;i<num;i++)
    {
        sum+=arr[i];
        arr[i]=-1*arr[i];
    }
    int y=kadane(arr,num);
    if(sum+y==0)
    {
        return x;
    }
    return max(x,sum+y);
    // your code here
}
