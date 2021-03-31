int subArraySum(int arr[], int n, int sum)
    {
        unordered_map<int,int>mp;
        int cs=0,cnt=0;
        for(int i=0;i<n;i++)
        {
            cs+=arr[i];
            if(cs==sum)
            {
                cnt++;
            }
            if(mp.find(cs-sum)!=mp.end())
            {
                cnt+=mp[cs-sum];
            }
            mp[cs]++;
        }
        return cnt;
    	//code here.
    }
