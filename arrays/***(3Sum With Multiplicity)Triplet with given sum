class Solution {
public:
    const long long mod=pow(10,9)+7;
    
    int threeSumMulti(vector<int>& arr, int k) 
    {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int count=0;
        const long long mod=pow(10,9)+7;
        for(int i=0;i<=n-2;i++)
        {
            int start=i+1;
            int end=n-1;
            while(start<end)
            {
                long long int sum=arr[i]+arr[start]+arr[end];
                if(sum<k)
                {
                    start++;
                    //continue;
                }
                else if(sum>k)
                {
                    end--;
                    //continue;
                }
                else
                {
                    int lp=1,rp=1;
                    while(start<end and arr[start]==arr[start+1])
                    {
                        lp++;
                        start++;
                    }
                    while(start<end and arr[end]==arr[end-1])
                    {
                        rp++;
                        end--;
                    }
                    if(start==end)
                    {
                        count+=lp*(lp-1)/2;
                    }
                    else
                    {
                        count+=(lp*rp);
                    }
                    count=count%mod;
                    start++;
                    end--;
                }
            }
        }
        return count;
    }
};
