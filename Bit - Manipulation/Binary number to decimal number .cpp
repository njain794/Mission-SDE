class Solution
{
	public:
		int binary_to_decimal(string str)
		{
		    int ans=0;
		    reverse(str.begin(),str.end());
		    for(int i=0;i<str.size();i++)
		    {
		        if(str[i]-'0'==1)
		        {
		            //int ex=str[i]-'0';
		            ans+=pow(2,i);
		        }
		    }
		    return ans;
		    // Code here.
		}
};
