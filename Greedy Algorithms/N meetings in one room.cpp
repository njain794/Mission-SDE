struct meeting{
    int start;
    int end;
    int pos;
};
bool cmp(struct meeting m1,struct meeting m2)
{
    return m1.end<m2.end;
}
int maxMeetings(int start[], int end[], int n) 
{
    struct meeting meet[n];
    
    for(int i=0;i<n;i++)
    {
        meet[i].start=start[i];
        meet[i].end=end[i];
        meet[i].pos=i+1;
    }
    
    sort(meet,meet+n,cmp);
    
    vector<int>v;
    int limit=meet[0].end;
    v.push_back(meet[0].pos);
    for(int i=1;i<n;i++)
    {
        if(meet[i].start>limit)
        {
            v.push_back(meet[i].pos);
            limit=meet[i].end;
        }
    }
    
    return v.size();
    // Your code here
}
