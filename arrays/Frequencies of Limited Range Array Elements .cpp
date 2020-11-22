void frequencycount(vector<int>& a,int n)
{ 
    //int *temp=new int[n];
    int temp[n+1]={0};
    for(int i=0;i<n;i++)
    {
        temp[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        a[i]=temp[i+1];
    }
    // code here
}
