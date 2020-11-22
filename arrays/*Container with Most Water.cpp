long long maxArea(long long a[], int len)
{
    int low=0;
    int end=len-1;
    long long int area=0;
    while(low<end)
    {
        area=max(area,(min(a[low],a[end])*(end-low)));
        if(a[low]<a[end])
        {
            low++;
        }
        else
        {
            end--;
        }
    }
    return area;
    // Your code goes here
}
