
int minSwap(int *arr, int n, int k) 
{
    int win_size=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=k)
        {
            win_size++;
        }
    }
    int count=0;
    for(int i=0;i<win_size;i++)
    {
        if(arr[i]>k)
        {
            count++;
        }
    }
    int res=count;
    int i=0,j=win_size;
    while(j<n)
    {
        if(arr[i]>k)
        {
            count--;
        }
        if(arr[j]>k)
        {
            count++;
        }
        res=min(res,count);
        i++;
        j++;
    }
    return res;
    
    
    /*int good=0,bad=0;
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
    }*/
    // Complet the function
}
