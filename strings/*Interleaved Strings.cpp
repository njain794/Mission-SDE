class Solution{
  public:
    /*You are required to complete this method */
    
    bool solve(int i,int j,int k,string a,string b,string c)
    {
        if(i==a.size() and j==b.size() and k==c.size())
        {
            return true;
        }
        if(k==c.size())
        {
            return false;
        }
        
        bool b1=false;
        bool b2=false;
        if(a[i]==c[k])
        {
            b1=solve(i+1,j,k+1,a,b,c);
        }
        if(b[j]==c[k])
        {
            b2=solve(i,j+1,k+1,a,b,c);
        }
        return (b1 or b2);
    }
    bool isInterleave(string a, string b, string c) 
    {
        int i=0;
        int j=0;
        int k=0;
        
        return solve(i,j,k,a,b,c);
        //Your code here
    }

};
