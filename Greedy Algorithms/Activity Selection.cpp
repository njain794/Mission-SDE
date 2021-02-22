struct activity
{
    int arr;
    int dep;
};
bool cmp(struct activity d1,struct activity d2)
{
    return d1.dep<d2.dep;
}
int activitySelection(int start[], int end[], int n)
{
    struct activity day[n];
    
    for(int i=0;i<n;i++)
    {
        day[i].arr=start[i];
        day[i].dep=end[i];
    }
    
    sort(day,day+n,cmp);
    
    int limit=day[0].dep;
    int count=1;
    
    for(int i=1;i<n;i++)
    {
        if(day[i].arr>=limit)
        {
            count++;
            limit=day[i].dep;
        }
    }
    return count;
    // Your code here
}
