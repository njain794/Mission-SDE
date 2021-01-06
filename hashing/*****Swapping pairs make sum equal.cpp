class Solution{

	public:
	int sumn(int arr[],int s)
	{
	    int sum=0;
	    for(int i=0;i<s;i++)
	    {
	        sum+=arr[i];
	    }
	    return sum;
	}
	int findSwapValues(int A[], int n, int B[], int m)
	{
	    sort(A,A+n);
	    sort(B,B+m);
	    int s1=sumn(A,n);
	    int s2=sumn(B,m);
	    
	    if((s1-s2)%2!=0)
	    {
	        return -1;
	    }
	    int temp=(s1-s2)/2;
	    int i=0;
	    int j=0;
	    while(i<n and j<m)
	    {
	        if(A[i]-B[j]==temp)
	        {
	            return 1;
	        }
	        else if(A[i]-B[j]<temp)
	        {
	            i++;
	        }
	        else
	        {
	            j++;
	        }
	    }
	    return -1;
        // Your code goes here
	}
 

};
