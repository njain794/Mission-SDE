class Solution{
	public:
	int gcd(int a,int b)
	{
	    if(a==0)
	    {
	        return b;
	    }
	    return gcd(b%a,a);
	}
	string FindGcd(long long int  n, int x, int y)
	{
	    int v=gcd(x,y);
	    string d="";
	    string v1=to_string(n);
	    for(int i=0;i<v;i++)
	    {
	        d+=v1;
	    }
	    return d;
	    // Code here
	}
};
