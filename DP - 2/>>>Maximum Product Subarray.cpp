#define ll long long int
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) 
	{
	    ll maxp,minp,res;
	    
	    maxp=minp=res=1;
	    
	    for(int i=0;i<n;i++)
	    {
	        ll x = arr[i];
	        if(x<0)
	        {
	            swap(maxp,minp);
	        }
	        maxp=max(x,x*maxp);
	        minp=min(x,x*minp);
	        
	        res=max(res,maxp);
	    }
	    return res;
	    // code here
	}
};
