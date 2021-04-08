// https://practice.geeksforgeeks.org/problems/b6b3297ccfb1ad5f66a9c2b92979170417adf114/1/?track=30-DOC-day-9&batchId=320#
class Solution{
    
    public:
    int transfigure (string a, string b)
    {
        //transform(a.begin(), a.end(), a.begin(), ::tolower);
        //transform(b.begin(), b.end(), b.begin(), ::tolower);
        
        int n=a.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[a[i]]++;
            mp[b[i]]--;
        }
        
        for(auto x:mp)
        {
            if(x.second!=0)
            {
                return -1;
            }
        }
        
        int i=n-1;
        int j=n-1;
        int count=0;
        
        while(i>=0 and j>=0)
        {
            if(a[i]==b[j])
            {
                i--;
                j--;
            }
            else
            {
                count++;
                i--;
            }
        }
        return count;
    	// Your code goes here
    }
};
