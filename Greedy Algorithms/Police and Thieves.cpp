// https://practice.geeksforgeeks.org/problems/e47329920b4e75869ea7b0e9b7c59ea145ccc22c/1/?track=30-DOC-day-27&batchId=320
class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]=='P')
            {
                int v1=i-k;
                int v2=i+k;
                if(v1<0)
                {
                    v1=0;
                }
                if(v2>=n)
                {
                    v2=n-1;
                }
                
                for(int j=v1;j<=v2;j++)
                {
                    if(arr[j]=='T')
                    {
                        cnt++;
                        arr[j]='C';
                        break;
                    }
                }
            }
            //return cnt;
        }
        return cnt;
        // Code here 
    }
};
