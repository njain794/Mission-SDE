class Solution
{
    public:
    
    void solve(int open,int close,string temp,vector<string> &ans)
    {
        if(open==0 and close==0)
        {
            ans.push_back(temp);
            return;
        }
        if(open!=0)
        {
            string temp1=temp;
            temp1.push_back('(');
            solve(open-1,close,temp1,ans);
        }
        if(close>open)
        {
            string temp2=temp;
            temp2.push_back(')');
            solve(open,close-1,temp2,ans);
        }
    }
    
    vector<string> AllParenthesis(int n) 
    {
        int open=n;
        int close=n;
        
        string temp;
        vector<string>ans;
        solve(open,close,temp,ans);
        return ans;
        // Your code goes here 
    }
};
