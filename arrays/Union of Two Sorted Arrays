vector<int> findUnion(int a1[], int a2[], int n, int m)
{
    int i=0;
    int j=0;
    vector<int>v;
    while(i<n and j<m)
    {
        if(a1[i]==a2[j])
        {
            v.push_back(a1[i]);
            i++;
            j++;
        }
        else if(a1[i]<a2[j])
        {
            v.push_back(a1[i]);
            i++;
        }
        else if(a2[j]<a1[i])
        {
            v.push_back(a2[j]);
            j++;
        }
    }
    while(i<n)
    {
        v.push_back(a1[i]);
        i++;
    }
    while(j<m)
    {
        v.push_back(a2[j]);
        j++;
    }
    auto itr=unique(v.begin(),v.end());
    v.resize(distance(v.begin(),itr));
    return v;
}
