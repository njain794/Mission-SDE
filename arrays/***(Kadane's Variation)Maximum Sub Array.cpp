class Solution{
public:
	vector<int> findSubarray(int a[], int n) 
	{
	    long long int maxfar=0;
	    long long int res=0;
	    int start=-1,end=-1;
	    int s=0;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]>=0)
	        {
	            maxfar+=a[i];
	            if(maxfar>res)
	            {
	                res=maxfar;
	                start=s;
	                end=i;
	            }
	            else if(maxfar==res)
	            {
	                if(end-start<i-s)
	                {
	                    start=s;
	                    end=i;
	                }
	            }
	        }
	        else
	        {
	            maxfar=0;
	            s=i+1;
	        }
	    }
	    vector<int>v;
	    if(start==-1 and end==-1)
	    {
	        v.push_back(-1);
	    }
	    else
	    {
	        for(int i=start;i<=end;i++)
	        {
	            v.push_back(a[i]);
	        }
	    }
	    return v;
	    // code here
	}
};
