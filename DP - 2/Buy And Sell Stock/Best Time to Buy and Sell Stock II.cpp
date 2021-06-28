class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        int profit=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i-1]<arr[i])
            {
                profit+=arr[i]-arr[i-1];
            }
        }
        
        return profit;
    }
};
