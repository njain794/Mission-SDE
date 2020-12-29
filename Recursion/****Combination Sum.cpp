void solve(vector<int>arr,int sum,int index,vector<int>temp,vector<vector<int>>&res)
{
    if(sum==0)
    {
        res.push_back(temp);
        return;
    }
    for(int i=index;i<arr.size();i++)
    {
        if(arr[i]<=sum)
        {
            temp.push_back(arr[i]);
            sum=sum-arr[i];
            solve(arr,sum,i,temp,res);
            sum=sum+arr[i];
            temp.pop_back();
        }
    }
}
vector<vector<int> > combinationSum(vector<int> &arr, int B) 
{
    sort(arr.begin(),arr.end());
    auto itr=unique(arr.begin(),arr.end());
    arr.resize(distance(arr.begin(),itr));
    
    vector<int>temp;
    vector<vector<int>>res;
    int sum=B;
    int index=0;
    solve(arr,sum,index,temp,res);
    return res;
    // Your code here
}
