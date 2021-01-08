int maxSubArray(vector<int> v) 
{
    int maxfr=0;
    int res=0;
    for(int i=0;i<v.size();i++)
    {
        maxfr+=v[i];
        if(maxfr<0)
        {
            maxfr=0;
        }
        if(maxfr>res)
        {
            res=maxfr;
        }
    }
    if(res==0)
    {
        return *max_element(v.begin(),v.end());
    }
    else
    {
        return res;
    }
    // code here      
}
