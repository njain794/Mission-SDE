void solve(int arr[],int n)
{
    int i=-1;
    for(int j=0;j<n;j++)
    {
        if(arr[j]<0)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    int pos=i+1;
    int neg=0;
    while(pos<n and neg<pos and arr[neg]<0)
    {
        swap(arr[pos],arr[neg]);
        neg+=2;
        pos++;
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
