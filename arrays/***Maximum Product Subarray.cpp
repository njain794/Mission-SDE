class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int maxans=nums[0];
        int tempmin=maxans;
        int tempmax=maxans;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                swap(tempmin,tempmax);
            }
            tempmin=min(nums[i]*tempmin,nums[i]);
            tempmax=max(nums[i]*tempmax,nums[i]);
            maxans=max(maxans,tempmax);
        }
        return maxans;
    }
};
***********************************************
long long maxProduct(int *arr, int n) 
	{
	    long long int maxans=1;
	    long long int tempmax=1;
	    long long int tempmin=1;
	    long long int d=1;
	    
	    for(int i=0;i<n;i++)
	    {
	        long long x=arr[i];
	        
	        if(x>0)
	        {
	            tempmax=tempmax*x;
	            tempmin=min(tempmin*x,d);
	        }
	        else if(arr[i]==0)
	        {
	            tempmax=d;
	            tempmin=d;
	        }
	        else
	        {
	            int temp=tempmax;
	            tempmax=max(tempmin*x,d);
	            tempmin=temp*x;
	        }
	        
	        if(tempmax>maxans)
	        {
	            maxans=tempmax;
	        }
	    }
	    return maxans;
	    // code here
	}
