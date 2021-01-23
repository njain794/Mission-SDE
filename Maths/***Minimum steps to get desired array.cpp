class Solution{   
public:
    int countMinOperations(int arr[], int n) 
    {
        int result=0;
        while(1)
        {
            int zeros=0;
            int i=0;
            for(i=0;i<n;i++)
            {
                if(arr[i]%2!=0)
                {
                   break; 
                }
                if(arr[i]==0)
                {
                    zeros++;
                }
            }
            
            if(zeros==n)
            {
                return result;
            }
            
            if(i==n)
            {
                for(int j=0;j<n;j++)
                {
                    arr[j]=arr[j]/2;
                    //result++;
                }
                result++;
            }
            
            else 
            {
                for(int j=0;j<n;j++)
                {
                    if(arr[j]%2!=0)
                    {
                        arr[j]--;
                        result++;
                    }
                }
            }
            
        }
        return result;
        // code here
    }
};
