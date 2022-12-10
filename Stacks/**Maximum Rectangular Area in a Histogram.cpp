  vector<long long int> nsl(long long v[], int n)
    {
        stack<long long int>st;
        vector<long long int>ans;
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                ans.push_back(-1);
            }
            else if(!st.empty() && v[st.top()]<v[i])
            {
                ans.push_back(st.top());
            }
            else if(!st.empty() && v[st.top()]>=v[i])
            {
                while(!st.empty() && v[st.top()]>=v[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    ans.push_back(-1);
                }
                else
                {
                    ans.push_back(st.top());
                }
            }
            st.push(i);
        }
        return ans;
    }
    
    vector<long long int> nsr(long long v[], int n)
    {
        stack<long long int>st;
        vector<long long int>ans;
        
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                ans.push_back(n);
            }
            else if(!st.empty() && v[st.top()]<v[i])
            {
                ans.push_back(st.top());
            }
            else if(!st.empty() && v[st.top()]>=v[i])
            {
                while(!st.empty() && v[st.top()]>=v[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    ans.push_back(n);
                }
                else
                {
                    ans.push_back(st.top());
                }
            }
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long v[], int n)
    {
        auto l=nsl(v,n);
        auto r=nsr(v,n);
        long long int ans=v[0];
        
        for(int i=0;i<n;i++)
        {
            //cout<<v[i]<<" "<<l[i]<<" "<<r[i]<<"\n";
            long long int tempAns = v[i]*(r[i]-l[i]-1);
            ans=max(ans,tempAns);
        }
        
        return ans;
    }
};
