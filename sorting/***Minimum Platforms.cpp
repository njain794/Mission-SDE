int findPlatform(int arr[], int dep[], int n)
{
    sort(arr,arr+n);
    sort(dep,dep+n);
    
    int i=1;
    int j=0;
    int currp=1;
    int maxp=1;
    while(i<n and j<n)
    {
        if(arr[i]<=dep[j])
        {
            currp++;
            i++;
            maxp=max(maxp,currp);
        }
        else
        {
            currp--;
            j++;
        }
    }
    return maxp;
	// Your code here
}
