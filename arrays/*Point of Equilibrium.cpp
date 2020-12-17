//https://practice.geeksforgeeks.org/contest-problem/point-of-equilibrium3856/1
void eqPoint(int arr[],int n)
{
    if(n==1)
    {
        cout<<"-1\n";
        return;
    }
    long long mul=1;
    for(int i=0;i<n;i++)
    {
        mul=mul*arr[i];
    }
    
    long long lmul=1;
    long long rmul=1;
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        lmul=lmul*arr[i];
        rmul=mul/lmul;
        if(lmul==rmul)
        {
            cout<<i+1<<"."<<i+2<<"\n";
            //flag=true;
            return;
        }
    }
    cout<<"-1"<<"\n";
    return;
