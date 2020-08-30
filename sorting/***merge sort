void merge(int arr[], int l, int m, int r)
{
    /*int i=l;
    int j=m+1;
    int temp[999];
    int k=0;
    
    while(i<=m and j<=r)
    {
        if(a[i]<a[j])
        {
            temp[k]=a[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=m)
    {
        temp[k]=a[i];
        k++;
        i++;
    }
    while(j<=r)
    {
        temp[k]=a[j];
        k++;
        j++;
    }
    int g=0;
    for(int t=l;t<=r;t++)
    {
        a[t]=temp[g];
        g++;
    }
    return;
     // Your code here*/
     int n1 = m - l + 1;
    int n2 = r - m;
    
    int left[n1], right[n2];
    
    int i,j,k;
    
    for(i=0; i<n1; i++)
        left[i] = arr[l+i];
        
    for(j=0; j<n2; j++)
        right[j] = arr[m + j + 1];
    
    i=0, j=0, k=l;
    
    while(i<n1 && j<n2){
        if(left[i] <right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
            
    }
    
    while(i<n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}
