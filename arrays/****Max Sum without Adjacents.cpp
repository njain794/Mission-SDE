class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) 
	{
	    if(n==1)
	    {
	        return arr[0];
	    }
	    if(n==2)
	    {
	        return max(arr[0],arr[1]);
	    }
	    int a=arr[0];
	    int b=max(arr[0],arr[1]);
	    int c;
	    for(int i=2;i<n;i++)
	    {
	        c=max(b,a+arr[i]);
	        a=b;
	        b=c;
	    }
	    return c;
	    // code here
	}
};
