bool subArrayExists(int arr[], int n)
{
    int sum=0;
    unordered_set<int>st;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            return true;
        }
        sum+=arr[i];
        if(sum==0)
        {
            return true;
        }
        else if(st.find(sum)!=st.end())
        {
            return true;
        }
        st.insert(sum);
    }
    return false;
    //Your code here
    
}
