class marks
{
    public:
        int phy;
        int chem;
        int math;
};
class Solution{
    public:
    
    static bool cmp(const marks a,const marks b)
    {
        if(a.phy!=b.phy)
        {
            return (a.phy<b.phy);
        }
        else 
        {
            if(a.chem!=b.chem)
            {
                return (a.chem>b.chem);
            }
            else
            {
                return (a.math<b.math);
            }
        }
        return false;
    }

    void customSort (int phy[], int chem[], int math[], int n)
    {
        marks arr[n];
        
        for(int i=0;i<n;i++)
        {
            arr[i].phy=phy[i];
            arr[i].chem=chem[i];
            arr[i].math=math[i];
        }
        
        sort(arr,arr+n,cmp);
        
        for(int i=0;i<n;i++)
        {
            phy[i]=arr[i].phy;
            chem[i]=arr[i].chem;
            math[i]=arr[i].math;
        }
        // your code here
    } 
};
