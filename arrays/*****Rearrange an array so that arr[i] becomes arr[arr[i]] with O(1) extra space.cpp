class Solution {
  public:
    void prank(long long arr[], int n)
    {
    // First step: Increase all values by (arr[arr[i]]%n)*n
    for (int i=0; i < n; i++)
        arr[i] += (arr[arr[i]]%n)*n;
 
    // Second Step: Divide all values by n
    for (int i=0; i<n; i++)
        arr[i] /= n;
        // code here
    }
};
