bool findTriplets(int arr[], int n)
{ 
    sort(arr,arr+n);
    for(int i=0;i<=n-3;i++)
    {
        int a=i+1;
        int b=n-1;
        while(a<b)
        {
            int sum=arr[i]+arr[a]+arr[b];
            if(sum==0)
            {
                return true;
            }
            else if(sum<0)
            {
                a++;
            }
            else if(sum>0)
            {
                b--;
            }
        }
    }
    return false;
    //Your code here
}
