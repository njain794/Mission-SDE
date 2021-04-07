// https://practice.geeksforgeeks.org/problems/620fb6456d6515faddd77050dfbf2821d7a94b8a/1/?track=30-DOC-day-4&batchId=320

class Solution{

	public:
	int find_min(int a[], int n, int k) 
	{
	    int sum=0;
	    int p=0;
	    for(int i=0;i<n;i++)
	    {
	        p+=a[i]/2;
	        if(a[i]%2==0)
	        {
	            sum+=a[i]-2;
	        }
	        else
	        {
	            sum+=a[i]-1;
	        }
	    }
	    
	    if(p<k)
	    {
	        return -1;
	    }
	    
	    sum=sum/2;
	    if(sum<k)
	    {
	        return (2*sum)+n+(k-sum);
	    }
	    else
	    {
	        return (2*(k-1))+n+1;
	    }
        // Your code geos here
    }

};
