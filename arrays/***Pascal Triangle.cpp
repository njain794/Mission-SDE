class Solution{
    int MOD=1000000007;
public:
    vector<ll> nthRowOfPascalTriangle(int n) 
    {
        vector<vector<ll>>v(n);
        for(int i=0;i<n;i++)
        {
            v[i].resize(i+1);
            v[i][0]=1;
            v[i][i]=1;
            for(int j=1;j<i;j++)
            {
                v[i][j]=(v[i-1][j-1]+v[i-1][j])%MOD;
            }
        }
        vector<ll>ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(v[n-1][i]);
        }
        return ans;
        // code here
    }
};
