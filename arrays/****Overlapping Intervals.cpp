vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> v, int n) 
{
    sort(v.begin(),v.end());
    int i=0;
    while(i<v.size()-1)
    {
        if(v[i].second>=v[i+1].first)
        {
            pair<int,int>p=make_pair(v[i].first,max(v[i].second,v[i+1].second));
            v[i]=p;
            v.erase(v.begin()+i+1);
        }
        else
        {
            i++;
        }
    }
    return v;
    //code here
}
