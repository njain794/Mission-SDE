class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) 
    {
        int sum=arr2[0];
        for(int i=1;i<arr2.size();i++)
        {
            sum^=arr2[i];
        }
        
        int ans=arr1[0]&sum;
        for(int j=1;j<arr1.size();j++)
        {
            ans^=(arr1[j]&sum);
        }
        return ans;
    }
};
