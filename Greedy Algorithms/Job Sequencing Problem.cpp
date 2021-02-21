class Solution {
  public:
    bool cmp(Job a1,Job a2)
    {
        return a1.profit<a2.profit;   
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        
        int slot[n+1];
        for(int i=0;i<n;i++)
        {
            slot[i]=-1;
        }
        
        int days=0,profit=0;
        for(int i=0;i<n;i++)
        {
            for(int j=min(n,arr[i].dead-1);j>=0;j--)
            {
                if(slot[j]==-1)
                {
                    days+=1;
                    slot[j]=arr[i].dead;
                    profit+=arr[i].profit;
                    break;
                }
            }
        }
        vector<int>ans;
        ans.push_back(days);
        ans.push_back(profit);
        return ans;
        // your code here
    } 
};
