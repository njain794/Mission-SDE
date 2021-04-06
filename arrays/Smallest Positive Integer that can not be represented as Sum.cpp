class Solution
{   
public:
    long long smallestpositive(vector<long long> arr, int n)
    { 
        sort(arr.begin(), arr.end());
        long long int res = 1;


        for (int i = 0; i < n && arr[i] <= res; i++)
        {
            res = res + arr[i];
        }    
        
        return res;
        // code here 
    } 
};
