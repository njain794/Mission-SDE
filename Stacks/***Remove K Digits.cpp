https://practice.geeksforgeeks.org/problems/remove-k-digits/1#

class Solution{
    public:
    string removeKdigits(string str, int k) 
    {
        stack<char>st;
        string ans;
        
        for(auto c:str)
        {
            while(!st.empty() and k>0 and st.top()>c)
            {
                st.pop();
                k--;
            }
            if(!st.empty() or c!='0')
            {
                st.push(c);
            }
        }
        
        while(!st.empty() and k--)
        {
            st.pop();
        }
        if(st.empty())
        {
            return "0";
        }
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
