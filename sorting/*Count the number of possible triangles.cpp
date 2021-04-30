class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        sort(arr,arr+n);
        int cnt=0;
        
        for(int i=n-1;i>=2;i--)
        {
            int a=0;
            int b=i-1;
            while(a<b)
            {
                if(arr[a]+arr[b]>arr[i])
                {
                    cnt+=b-a;
                    b--;
                }
                else
                {
                    a++;
                }
            }
        }
        return cnt;
        // code here
    }
};
