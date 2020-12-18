int maxIndexDiff(int arr[], int n) 
{ 
    int res=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=n-1;j>=i;j--)
        {
            if(arr[i]<=arr[j])
            {
                res=max(res,(j-i));
                break;
            }
        }
    }
    return res;
    // Your code here
    
}
