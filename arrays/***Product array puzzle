vector<long long int> productExceptSelf(vector<long long int>& v, int n) 
{
    vector<long long int>p; 
    long long int left[1000];
    long long int right[1000];
    left[0]=1;
    right[n-1]=1;
    for(int i=1;i<n;i++)
    {
        left[i]=left[i-1]*v[i-1];
    }
    for(int i=n-2;i>=0;i--)
    {
        right[i]=right[i+1]*v[i+1];
    }
    for(int i=0;i<n;i++)
    {
        p.push_back(left[i]*right[i]);
    }
    return p;
    //code here        
}
