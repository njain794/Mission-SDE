class Solution{
public:
    int *findTwoElement(int *arr, int n) 
    {
        int i=0;
        int *brr=new int[2];
        while(i<n)
        {
            if(arr[i]!=arr[arr[i]-1])
            {
                swap(arr[i],arr[arr[i]-1]);
            }
            else
            {
                i++;
            }
        }
        int j=0;
        for(int i1=0;i1<n;i1++)
        {
            if(arr[i1]!=i1+1)
            {
                brr[j]=arr[i1];
                j++;
                brr[j]=i1+1;
                break;
            }
        }
        return brr;
        // code here
    }
};
