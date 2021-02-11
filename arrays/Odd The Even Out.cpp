vector<pair<long long, long long>> vectorIterator(vector<pair<long long, long long>> &v)
{
    for(long long int i=0;i<v.size();i++)
    {
        pair<long long,long long>p=v[i];
        if((p.second&1)==0)
        {
            v.erase(v.begin()+i);
            i--;
        }
    }
    //return v;
    // Your code here
    
    return v;
    
}
