int equilibriumPoint(long long a[], int n) 
{
    //vector<int>left;
    //vector<int>right;
    if(n==1)
    {
        return 1;
    }
    int sum=0;
    int ls=0;
    //int rs=0;
    
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    for(int i=0;i<n;i++)
    {
        ls=ls+a[i];
        if(ls==sum)
        {
            return i+1;
        }
        sum=sum-a[i];
    }
    return -1;
    // Your code here
}
