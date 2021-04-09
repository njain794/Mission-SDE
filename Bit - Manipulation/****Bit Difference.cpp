// https://practice.geeksforgeeks.org/problems/760a2a0627f1abf231de42b93bb71825ecbcb3b4/1/?track=30-DOC-day-12&batchId=320
class Solution{
    public:
    long long sumBitDiff(int arr[], int n) 
    { 
        long long int ans=0;
        for(int i=0;i<32;i++)
        {
            long long int count=0;
            for(int j=0;j<n;j++)
            {
                if(arr[j] & 1<<i)
                {
                    count++;
                }
            }
            ans+=count*(n-count)*2;
        }
        return ans;
        // Your code goes here
    } 
};
