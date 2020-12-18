//see variation of leetcode - return all 3 sum with zero values
bool findTriplets(int arr[], int n)
{ 
    sort(arr,arr+n);
    for(int i=0;i<=n-3;i++)
    {
        if(i==0 or (i>0 and arr[i]!=arr[i-1]))
        {
            int left=i+1;
            int right=n-1;
            int sum = -1*arr[i];
            while(left<right)
            {
                if(arr[left]+arr[right]==sum)
                {
                    return true;
                    left++;
                    right--;
                }
                else if(arr[left]+arr[right]<sum)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }
    return false;
    //Your code here
}
