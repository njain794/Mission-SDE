
bool find3Numbers(int arr[], int n, int x)
{
    sort(arr,arr+n);
    for(int i=0;i<=n-3;i++)
    {
        int a=i+1;
        int b=n-1;
        while(a<b)
        {
            int sum=arr[i]+arr[a]+arr[b];
            if(sum==x)
            {
                return true;
            }
            else if(sum<x)
            {
                a++;
            }
            else if(sum>x)
            {
                b--;
            }
        }
    }
    return false;
    //Your Code Here
}
