class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	static bool comp(const string s1,const string s2)
	{
	    return (s1+s2)>(s2+s1);
	}
	string printLargest(vector<string> &arr) 
	{
	    sort(arr.begin(),arr.end(),comp);
	    //stack<string>st;
	    string ans;
	    for(auto x:arr)
	    {
	        ans+=x;
	    }
	    return ans;
	    // code here
	}
};
