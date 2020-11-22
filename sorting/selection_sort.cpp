int select(int arr[], int i,int n)
{
    int min=i;
    for(int j=i+1;j<n;j++)
    {
        if(arr[j]<arr[min])
        {
            min=j;
        }
    }
    return min;
    // code here such that selectionSort() sorts arr[]
}
 
void selectionSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i <n-1; i++)      
   {
        int j = select(arr, i,n);
        swap(&arr[i], &arr[j]);
   }
}
