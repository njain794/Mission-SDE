// https://practice.geeksforgeeks.org/problems/3b76f77c1b2107f809b1875aa9fe929ce320be97/1/?track=30-DOC-day-7&batchId=320#

class Solution{
    
    public:
    long long ValidPair(int a[], int n) 
    { 
        sort(a,a+n);
        long long sum=0;
        int f=0;
        int t=n-1;
        
        while(f<t)
        {
            if(a[f]+a[t]>0)
            {
                sum+=(t-f);
                t--;
            }
            else
            {
                f++;
            }
        }
        
        return sum;
    	// Your code goes here 
    }   
};
