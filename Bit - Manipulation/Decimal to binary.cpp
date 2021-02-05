void toBinary(int n)
{
    int arr[1000];
    int i=0;
    while(n!=1)
    {
        if(n&1)
        {
            arr[i++]=1;
            
        }
        else
        {
            arr[i++]=0;
            
        }
        n=n/2;
    }
    
    arr[i++]=1;
    for(int j=i-1;j>=0;j--)
    {
        printf("%d",arr[j]);
    }
    // your code here
        
}
