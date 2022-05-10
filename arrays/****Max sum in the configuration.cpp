int max_sum(int arr[],int n)
{
    int ms=0;
    for(int i=0;i<n;i++)
    {
        ms+=arr[i];
    }
    int s=0;
    for(int i=0;i<n;i++)
    {
        s=s+(i*arr[i]);
    }
    int ans=s;
    for(int i=1;i<n;i++)
    {
        int temp=(s-ms)+arr[i-1]*n;
        ans=max(ans,temp);
        s=temp;
    }
    return ans;
//Your code here
}
**************************************
int max_sum(int arr[],int n){
    int sum = 0;
    int sum2 = 0;
    int maxsum = INT_MIN;
    for(int j = 0; j < n; j ++){
        sum += arr[j] * j;
        sum2 += arr[j];
    }
    for(int i = 0; i < n; i++){
        sum2 -= arr[i];
        sum = sum - sum2;
        sum = sum + (n-1)*arr[i];
        maxsum = max(sum,maxsum);
        sum2 += arr[i];
    }
    return maxsum;
}
