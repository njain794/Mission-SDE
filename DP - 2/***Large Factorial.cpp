class Solution{
public:

    int mod=pow(10,9)+7;
    long long int solve(vector<long long> &temp,long long int d)
    {
        temp[0]=1;
        temp[1]=1;
        
        for(long long int i=2;i<=d;i++)
        {
            temp[i]=(i*temp[i-1])%mod;
        }
    }

    vector<long long> factorial(vector<long long> a, int n) 
    {
        vector<long long int>v(n);
        long long mx=*max_element(a.begin(),a.end());
        
        vector<long long int>temp(mx+1);
        solve(temp,mx);
        
        for(long long int i=0;i<n;i++)
        {
            v[i]=temp[a[i]];
        }
        return v;
    }
};
