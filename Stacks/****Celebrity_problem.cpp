class Solution {
    public:
    int celebrity(vector<vector<int> >& mat, int n) 
    {
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        while(st.size()>1)
        {
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            
            if(mat[x][y]==1)
            {
                st.push(y);
            }
            else if(mat[x][y]==0)
            {
                //st.push(y);
                st.push(x);
            }
        }
        int d=st.top();
        int res=d;
        for(int i=0;i<n;i++)
        {
            if(mat[d][i]==1 or mat[i][d]==0 and i!=d)
            {
                res=-1;
                break;
            }
        }
        return res;
        // code here 
    }
};
