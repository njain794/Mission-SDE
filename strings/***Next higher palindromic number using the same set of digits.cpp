class Solution{
    public:
    string nextPalin(string str) 
    {
        if(str.size()<=3)
        {
            return "-1";
        }
        
        int mid=(str.size()/2)-1;
        
        string s1=str.substr(0,mid+1);
        string temp=s1;
        
        next_permutation(temp.begin(),temp.end());
        
        if(s1>=temp)
        {
            return "-1";
        }
        
        string ans;
        ans+=temp;
        if(str.size()%2!=0)
        {
            ans.push_back(str[str.size()/2]);
        }
        
        string s2=temp;
        reverse(s2.begin(),s2.end());
        ans+=s2;
        
        return ans;
        //complete the function here
    }
};
