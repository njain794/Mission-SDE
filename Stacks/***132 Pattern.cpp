class Solution{
public:
	bool recreationalSpot(int nums[], int n)
	{
	    int mini[n];
	    mini[0]=nums[0];
        
        for(int i=1;i<n;i++)
        {
            mini[i]=min(mini[i-1],nums[i]);
        }
        
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>mini[i])
            {
                while(!st.empty() and st.top()<=mini[i])
                {
                    st.pop();
                }
                if(!st.empty() and st.top()<nums[i])
                {
                    return true;
                }
            }
            st.push(nums[i]);
        }
        return false;
		// Your code goes here 
	}
};
