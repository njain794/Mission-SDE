int mah(int a[],int n)
{
    int b[n];
    stack<pair<int,int>> s;
    s.push(make_pair(a[n-1],n-1));
    pair<int,int> p;
    b[n-1] = n;
    for(int i=n-2;i>=0;i--)
    {
        p = s.top();
        if(p.first < a[i])
            b[i] = p.second;
        else
        {
            while(!s.empty() && p.first >= a[i])
            {
                s.pop();
                if(!s.empty())
                    p = s.top();
            }
            if(!s.empty())
                b[i] = p.second;
            else
                b[i] = n;
        }
        s.push(make_pair(a[i],i));
    }
    while(!s.empty())
        s.pop();
    s.push(make_pair(a[0],0));
    for(int i=1;i<n;i++)
    {
        p = s.top();
        if(p.first < a[i])
            b[i] = b[i] - p.second - 1;
        else
        {
            while(!s.empty() && p.first >= a[i])
            {
                s.pop();
                if(!s.empty())
                    p = s.top();
            }
            if(!s.empty())
                b[i] = b[i] - p.second - 1;
        }
        s.push(make_pair(a[i],i));
    }
    int ans = INT_MIN;
    for(int i=0;i<n;i++)
    {
        ans = max(ans,a[i]*b[i]);
    }
    return ans;
}

int maxArea(int M[MAX][MAX], int n, int m)
{
    int a[m] = {0};
    int ans = INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(M[i][j] == 0)
                a[j] = 0;
            else
                a[j] = a[j] + M[i][j];
        }
        ans = max(ans,mah(a,m));
    }
    return ans;
}


