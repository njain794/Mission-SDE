int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N)
    {
        sort(X.rbegin(),X.rend());
        sort(Y.rbegin(),Y.rend());

        int i=0,j=0;
        int x=1,y=1;
        int ans=0;
        
        while(i<M-1 && j<N-1)
        {
            if(X[i]>=Y[j])
            {
                ans+=X[i]*x;
                y++;
                i++;
            }
            else{
                ans+=Y[j]*y;
                x++;
                j++;
            }
        }
        
        while(i<M-1)
        {
            ans+=X[i]*x;
            i++;
            //y++;
        }
        while(j<N-1)
        {
            ans+=Y[j]*y;
            j++;
            //x++;
        }
        return ans;
    }
