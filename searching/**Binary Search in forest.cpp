int find_height(int tree[], int n, int k)
    {
        sort(tree,tree+n);
        int low=0;
        int high=tree[n-1];
        int ans=0;
        
        while(low<=high)
        {
            ans=0;
            int mid=(low+high)/2;
            for(int i=0;i<n;i++)
            {
                if(tree[i]>mid)
                {
                    ans+=tree[i]-mid;
                }
            }
            
            if(ans==k)
            {
                return mid;
            }
            else if(ans>k)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return -1;
        // code here
    }
