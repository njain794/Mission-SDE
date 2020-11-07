class Solution{
public:	
	int maxSubstring(string s)
	{
	    int c0=0,c1=0;
	    int cs;
	    int os=-1;
	    for(int i=0;i<s.size();i++)
	    {
	        if(s[i]-'0'==0)
	        {
	            c0++;
	        }
	        else if(s[i]-'0'==1)
	        {
	            c1++;
	        }
	        cs = c0-c1;
	        if(cs<0)
	        {
	            c0=0;
	            c1=0;
	            cs=0;
	        }
	        else if(cs>os)
	        {
	            os=cs;
	        }
	    }
	    return os;
	    // Your code goes here
	}
};
