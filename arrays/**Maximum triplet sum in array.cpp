int maxTripletSum(int arr[], int n)
{
    int m1=INT_MIN;
    int m2=INT_MIN;
    int m3=INT_MIN;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]>m1)
        {
            //m1=arr[i];
            //m2=m1;
            m3=m2;
            m2=m1;
            m1=arr[i];
        }
        else if(arr[i]>m2)
        {
            //m2=arr[i];
            m3=m2;
            m2=arr[i];
        }
        else if(arr[i]>m3)
        {
            m3=arr[i];
        }
    }
    
    return (m1+m2+m3);
    
    //// TLE ///
    /*int ms=INT_MIN;
    sort(arr,arr+n);
    for(int i=0;i<=n-3;i++)
    {
        int low=i+1;
        int end=n-1;
        while(low<end)
        {
            int cs=arr[i]+arr[low]+arr[end];
            if(cs<ms)
            {
                low++;
            }
            else
            {
                ms=max(cs,ms);
                end--;
            }
            //ms=max(cs,ms);
            
        }
    }
    return ms;*/
	// Complete the function
}
