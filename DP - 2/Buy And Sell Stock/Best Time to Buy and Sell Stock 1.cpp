class Solution {
public:
    int maxProfit(vector<int>& arr) 
    {
        int mn=arr[0];
        int profit=INT_MIN;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<mn)
            {
                mn=arr[i];
            }
            else if(arr[i]-mn>profit)
            {
                profit=arr[i]-mn;
            }
        }
        return profit;
    }
};
