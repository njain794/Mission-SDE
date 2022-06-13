class Solution{
public:	
	
	int isRepeat(string s)
	{
	    int n=s.size();
	    vector<int>v(n);
	    int len=0;
	    int i=1;
	    while(i<n)
	    {
	        if(s[i]==s[len])
	        {
	            v[i++]=++len;
	        }
	        else{
	            if(len==0)
	            {
	                v[i++]=0;
	            }
	            else{
	                len=v[len-1];
	            }
	        }
	    }
	    
	    int ans=v[n-1];
	    return (ans>0 && n%(n-ans)==0);
	}
};
