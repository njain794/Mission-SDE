class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int ternarySearch(int arr[], int n, int k) 
    { 
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid1=l+(r-l)/3;
            int mid2=r-(r-l)/3;
            
            if(arr[mid1]==k)
            {
                return 1;
            }
            if(arr[mid2]==k)
            {
                return 1;
            }
            
            else if(k<arr[mid1])
            {
                r=mid1-1;
            }
            else if(k>arr[mid2])
            {
                l=mid2+1;
            }
            
            else
            {
                l=mid1+1;
                r=mid2-1;
            }
        }
        return -1;
       // Your code here
       
    }
};
