class Solution{
	public:
    	long long findNth(long long n)
        {
            long long int sum=0;
            long long int place=1;
            
            while(n!=0)
            {
                sum+=place*(n%9);
                place=10*place;
                n=n/9;
            }
            
            return sum;
        // code here.
        }
};
