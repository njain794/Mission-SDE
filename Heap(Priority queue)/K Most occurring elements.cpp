int kMostFrequent(int arr[], int n, int k) 
{ 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    unordered_map<int,int>mp;
    
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        int x=it->second;
        int y=it->first;
        pair<int,int>pt=make_pair(x,y);
        
        pq.push(pt);
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
    int ans=0;
    while(pq.size()>0)
    {
        pair<int,int>pt=pq.top();
        ans+=pt.first;
        pq.pop();
    }
    return ans;
	// Your code here	
} 
