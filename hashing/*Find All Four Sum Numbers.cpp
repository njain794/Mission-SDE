class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) 
    {
        int n=arr.size();
        set<vector<int>>st;
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<=n-4;i++)
        {
            for(int j=i+1;j<=n-3;j++)
            {
                int left=j+1;
                int right=n-1;
                while(left<right)
                {
                    if(arr[i]+arr[j]+arr[left]+arr[right]==k)
                    {
                        vector<int>temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[left]);
                        temp.push_back(arr[right]);
                        st.insert(temp);
                        left++;
                        right--;
                    }
                    else if(arr[i]+arr[j]+arr[left]+arr[right]<k)
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
        
        vector<vector<int>> ans;
        for(auto x:st)
        {
            ans.push_back(x);
        }
        return ans;
        // Your code goes here
    }
};
