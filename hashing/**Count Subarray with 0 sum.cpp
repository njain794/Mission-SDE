ll findSubarray(vector<ll> arr, int n ) 
{
    //unordered_set<int>st;
    unordered_map<int,int>st;
    int ct=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0)
        {
            ct++;
        }
        if(st.find(sum)!=st.end())
        {
            ct+=st[sum];
        }
        st[sum]++;
    }
    return ct;
    //code here
}
