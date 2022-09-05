int canCut(int tree[], int n, int k, int mid)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(tree[i]>mid)
            {
                sum+=tree[i]-mid;
            }
        }
        return sum;
    }
    
    int find_height(int tree[], int n, int k)
    {
        if(n==1 && tree[0]>k)
        {
            return tree[0]-k;
        }
        sort(tree,tree+n);
        
        int low=tree[0];
        int hii=tree[n-1];
        int ans=-1;
        
        while(low<=hii)
        {
            int mid=low+(hii-low)/2;
            if(canCut(tree,n,k,mid)==k)
            {
                
                ans=mid;
                low=mid+1;
            }
            else if(canCut(tree,n,k,mid)>k)
            {
                low=mid+1;
            }
            else{
                hii=mid-1;
            }
        }
        return ans;
    }


**********************************************************

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
