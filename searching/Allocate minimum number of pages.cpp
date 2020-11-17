bool isvalid(int *arr,int n,int m,int mid)
{
    int student=1;
    int sum=0;
    
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>mid)
        {
            student++;
            sum=arr[i];
        }
        if(student>m)
        {
            return false;
        }
    }
    return true;
}
int findPages(int *arr, int n, int m) 
{
    int mx=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        mx=max(mx,arr[i]);
        sum+=arr[i];
    }
    int start=mx;
    int end=sum;
    int res=-1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(isvalid(arr,n,m,mid))
        {
            res=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return res;
    //code here
}
