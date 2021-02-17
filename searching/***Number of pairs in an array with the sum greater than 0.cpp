int ValidPair(int* arr, int n) 
{ 
    sort(arr,arr+n);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=0)
        {
            continue;
        }
        int j=lower_bound(arr,arr+n,(-1*arr[i])+1)-arr;
        count+=(i-j);
    }
    if(count<=-1)
    {
        count=0;
    }
    return count;
    // code here 
} 
