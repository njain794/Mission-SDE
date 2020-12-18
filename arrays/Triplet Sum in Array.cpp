#include <bits/stdc++.h>
using namespace std;

bool solve(int arr[],int n,int sum)
{
    sort(arr,arr+n);
    for(int i=0;i<=n-3;i++)
    {
        if(i==0 or (i>0 and arr[i]!=arr[i-1]))
        {
            int left=i+1;
            int right=n-1;
            int temp=sum-arr[i];
            while(left<right)
            {
                if(arr[left]+arr[right]==temp)
                {
                    return true;
                }
                else if(arr[left]+arr[right]<temp)
                {
                    left++;
                    //right--;
                }
                else
                {
                    right--;
                }
            }
        }
    }
    return false;
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,sum,arr[n];
        cin>>n;
        cin>>sum;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        if(solve(arr,n,sum))
        {
            cout<<"1\n";
        }
        else
        {
            cout<<"0\n";
        }
    }
	//code
	return 0;
}
