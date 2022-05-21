bool keypair(vector<int> a, int n, int x)
{
    /*int i=0;
    int j=n-1;
    int sum=0;
    sort(a.begin(),a.end());
    while(i<j)
    {
        sum=(a[i]+a[j]);
        if(sum<x)
        {
            i++;
        }
        else if(sum>x)
        {
            j--;
        }
        else
        {
            return true;
        }
    }
    return false;*/
    // Your code goes here
    set<int>s;
    
    for(int i=0;i<n;i++)
    {
        int temp=x-a[i];
        if(s.find(temp)!=s.end())
        {
            return true;
        }
        s.insert(a[i]);
    }
    return false;
}
