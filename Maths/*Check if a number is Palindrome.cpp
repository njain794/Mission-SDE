class Solution
{
	public:
		string is_palindrome(int n)
		{
		    int ans=0;
		    int f=n;
		    //int res=0;
		    while(n!=0)
		    {
		        int last=n%10;
		        n=n/10;
		        ans=ans*10+last;
		    }
		    //cout<<ans;
		    if(ans==f)
		    {
		        return "Yes";
		    }
		    else
		    {
		        return "No";
		    }
		    // Code here.
		}
};
