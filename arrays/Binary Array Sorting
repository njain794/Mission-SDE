vector<int> SortBinaryArray(vector<int> b)
{
    int temp[1000]={0};
    int n=b.size();
    vector<int>v;

    for(int i=0;i<n;i++)
    {
        temp[b[i]]++;
    }
    for(int i=0;i<=1;i++)
    {
        while(temp[i]>0)
        {
            v.push_back(i);
            temp[i]--;
        }
    }
    return v;
}
