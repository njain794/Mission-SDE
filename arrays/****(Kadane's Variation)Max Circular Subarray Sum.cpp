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

///////////////***** OR ******////////////////

int circularSubarraySum(int arr[], int n)
{
    if(n==1)
    {
        return arr[0];
    }
    
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    
    int cmax=arr[0];
    int resmax=arr[0];
    int cmin=arr[0];
    int resmin=arr[0];
    
    for(int i=1;i<n;i++)
    {
        cmax=max(cmax+arr[i],arr[i]);
        resmax=max(resmax,cmax);
        
        cmin=min(cmin+arr[i],arr[i]);
        resmin=min(resmin,cmin);
    }
    
    if(sum==resmin)
    {
        return resmax;
    }
    
    return max(resmax,(sum-resmin));
    // your code here
}
