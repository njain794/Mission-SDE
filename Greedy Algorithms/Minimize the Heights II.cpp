int getMinDiff(int arr[], int n, int k) 
    {
        sort(arr,arr+n);
        
        int small=arr[0]+k;
        int large=arr[n-1]-k;
        int ans=arr[n-1]-arr[0];
        int mi=0,ma=0;
        
        for(int i=0;i<n-1;i++)
        {
            mi=min(small,arr[i+1]-k);
            ma=max(large,arr[i]+k);
            if(mi<0)
            {
                continue;
            }
            ans=min(ans,ma-mi);
        }
        return ans;
        // code here
    }
