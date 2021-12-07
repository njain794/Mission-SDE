class Solution {
  public:
  
    int solve(int arr[],int n,int v)
    {
        sort(arr,arr+n);
        int ans=0;
        int j,k;
        for(int i=0;i<n-2;i++)
        {
            j=i+1;
            k=n-1;
            while(j!=k)
            {
                int sum=arr[i]+arr[j]+arr[k];
                if(sum>v)
                {
                    k--;
                }
                else
                {
                    ans+=(k-j);
                    j++;
                }
            }
        }
        return ans;
    }
  
    int countTriplets(int arr[], int n, int l, int r) 
    {
        return solve(arr,n,r)-solve(arr,n,l-1);
        // code here
    }
};
