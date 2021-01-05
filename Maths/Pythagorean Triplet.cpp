class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) 
	{
	    sort(arr,arr+n);
	    for(int i=2;i<n;i++)
	    {
	        int l=0;
	        int r=i-1;
	        int s2=(arr[i]*arr[i]);
	        while(l<r)
	        {
	            int s1=(arr[l]*arr[l])+(arr[r]*arr[r]);
	            //int s2=(arr[i]*arr[i]);
	            if(s1==s2)
	            {
	                return true;
	            }
	            else if(s1<s2)
	            {
	                l++;
	            }
	            else
	            {
	                r--;
	            }
	        }
	    }
	    return false;
	    // code here
	}
};
