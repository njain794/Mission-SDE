//https://practice.geeksforgeeks.org/contest/interview-series-microsoft/problems/

class Solution {
  public:
  
    int solve(int n, int a[])
    {
        vector<int>lis;
        
        lis.push_back(a[0]);
        for(int i=1;i<n;i++)
        {
            if(a[i]>lis.back())
            {
                lis.push_back(a[i]);
            }
            else
            {
                auto it=lower_bound(lis.begin(),lis.end(),a[i])-lis.begin();
                lis[it]=a[i];
            }
        }
        
        return lis.size();
       // your code here
    }
  
    int removeStudents(int arr[], int n) 
    {
        int l=solve(n,arr);
        return (n-l);
        // code here
    }
};
