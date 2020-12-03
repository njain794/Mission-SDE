class Solution{
	public:
   	vector<int> sophie_Primes(int N)
   	{
   	    int n=(2*N)+1;
   	    int prime[n]={0};
   	    
   	    for(int i=2;i<=n;i++)
   	    {
   	        if(prime[i]==0)
   	        {
   	            for(int j=i*i;j<=n;j+=i)
   	            {
   	                prime[j]=1;
   	            }
   	        }
   	    }
   	    vector<int>v;
   	    for(int i=2;i<N;i++)
   	    {
   	        if(prime[i]==0 and prime[2*i+1]==0)
   	        {
   	            v.push_back(i);
   	        }
   	    }
   	    return v;
   	    // Code here
   	}    
};
