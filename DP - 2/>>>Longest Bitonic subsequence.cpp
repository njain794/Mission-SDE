class Solution{
	public:
	int LongestBitonicSequence(vector<int>num)
	{
	    int n=num.size();
	    int lis[n],lds[n];
	    /*vector<int>lis;
	    vector<int>lds;
	    
	    for(int i=0;i<n;i++)
	    {
	        lis.push_back(1);
	        lds.push_back(1);
	    }*/
	    lis[0]=1;
	    for(int i=1;i<n;i++)
	    {
	        lis[i]=1;
	        for(int j=0;j<i;j++)
	        {
	            if(num[i]>num[j] and lis[i]<lis[j]+1)
	            {
	                lis[i]=lis[j]+1;
	            }
	        }
	    }
	    
	    lds[n-1]=1;
	    for(int i=n-2;i>=0;i--)
	    {
	        lds[i]=1;
	        for(int j=n-1;j>i;j--)
	        {
	            if(num[i]>num[j] and lds[i]<lds[j]+1)
	            {
	                lds[i]=lds[j]+1;
	            }
	        }
	    }
	    
	    int mx=lis[0]+lds[0]-1;
	    for(int i=1;i<n;i++)
	    {
	        mx=max(mx,lis[i]+lds[i]-1);
	    }
	    return mx;
	    // code here
	}
};
