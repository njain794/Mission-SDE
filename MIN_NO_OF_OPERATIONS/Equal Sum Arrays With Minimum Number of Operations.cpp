class Solution {
public:
    
    int solve(vector<int>n1,vector<int>n2,int s1,int s2)
    {
        int l2=1*n1.size();
        int r1=6*n2.size();
        if(r1<l2)
        {
            return -1;
        }
        
        int i=n1.size()-1;
        int j=0;
        int ops=0;
        while(i>=0 or j<n2.size())
        {
            if(s1<=s2)
            {
                break;
            }
            int change1=-1;
            int change2=-1;
            
            if(i>=0)
            {
                change1=n1[i]-1;
            }
            if(j<n2.size())
            {
                change2=6-n2[j];
            }
            
            if(change1>=change2)
            {
               s1=s1-n1[i]+1;
               i--; 
            }
            else if(change2>change1)
            {
                s2=s2-n2[j]+6;
                j++;
            }
            
            ops++;
        }
        return ops;
    }
    
    int minOperations(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int s1=0,s2=0;
        for(int i=0;i<nums1.size();i++)
        {
            s1+=nums1[i];
        }
        for(int j=0;j<nums2.size();j++)
        {
            s2+=nums2[j];
        }
        
        if(s1==s2)
        {
            return 0;
        }
        else
        {
            if(s1>s2)
            {
                return solve(nums1,nums2,s1,s2);
            }
            return solve(nums2,nums1,s2,s1);
        }
    }
};
