vector<int> TopK(vector<int>& arr, int k) 
{
    unordered_map<int,int>mp;
    vector<int>v;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
    int n=arr.size();
    
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        minh.push(make_pair(it->second,it->first));
        if(minh.size()>k)
        {
            minh.pop();
        }
    }
    
    while(minh.size()>0)
    {
        pair<int,int>p=minh.top();
        v.push_back(p.second);
        minh.pop();
    }
    reverse(v.begin(),v.end());
    return v;
}
