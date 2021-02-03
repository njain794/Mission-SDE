vector<int> subarraySum(int arr[], int n, int s)
{
    int i=0,j=0;
    long long int sum=0;
    vector<int>v;
    while(j<=n)
    {
        if(sum<s)
        {
            sum+=arr[j];
            j++;
        }
        else if(sum>s)
        {
            sum-=arr[i];
            i++;
        }
        
        if(sum==s)
        {
            v.push_back(i+1);
            v.push_back(j);
            return v;
        }
    }
    v.push_back(-1);
    return v;
    // Your code here
}
