int solve(int N, vector<int>&A, int L,int t)
    {
        int cnt=0;
        int sum=0;
        for(int i=0;i<L;i++)
        {
            sum=A[i];
            int j=2;
            while(sum<=t)
            {
                sum+=A[i]*j;
                j++;
                cnt++;
            }
        }
        return cnt>=N;
    }
    int findMinTime(int N, vector<int>&A, int L)
    {
        int low=0;
        int hii=1e7;
        int ans=0;
        
        while(low<=hii)
        {
            int mid = low+(hii-low)/2;
            if(solve(N,A,L,mid))
            {
                ans=mid;
                hii=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
