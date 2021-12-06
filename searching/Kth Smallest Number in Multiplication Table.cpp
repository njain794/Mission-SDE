// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    int solve(int mid,int n,int m)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            int temp=min(mid/i,m);
            cnt+=temp;
        }
        return cnt;
    }

    int KthSmallest(int m, int n, int k) 
    {
        int low=1;
        int hii=m*n;
        //int ans=hii;
        
        while(low<hii)
        {
            int mid=low+(hii-low)/2;
            if(solve(mid,n,m)>=k)
            {
                hii=mid;
                //ans=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
        //Write your code here
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n, k;
	    cin >> m >> n >> k;
	    Solution ob;
	    int ans = ob.KthSmallest(m, n, k);
	    cout << ans << endl;
	}
	return 0;
}
  // } Driver Code Ends
