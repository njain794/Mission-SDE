int minSwap(int *arr, int n, int k) 
{
    int good=0,bad=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=k)
        {
           good++; 
        }
    }
    for(int i=0;i<good;i++)
    {
        if(arr[i]>k)
        {
            bad++;
        }
    }
    int res=good;
    int i=0;
    int j=good-1;
    while(j<n)
    {
        res=min(res,bad);
        j++;
        if(j<n and arr[j]>k)
        {
            bad++;
        }
        if(arr[i]>k)
        {
            bad--;
        }
        i++;
    }
    if(res==INT_MAX)
    {
        return 0;
    }
    else
    {
        return res;
    }
    // Complet the function
}
