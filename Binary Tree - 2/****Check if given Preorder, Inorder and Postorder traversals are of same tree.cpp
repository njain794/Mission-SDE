class Solution{
    public:
    bool checktree(int pre[], int in[], int post[], int n) 
    { 
        if(n==0)
        {
            return true;
        }
        if(n==1)
        {
            return ((pre[0]==in[0]) and (post[0]==in[0]));
        }
        
        if(pre[0]!=post[n-1])
        {
            return false;
        }
        
        int idx=-1;
        for(int i=0;i<n;i++)
        {
            if(in[i]==pre[0])
            {
                idx=i;
                break;
            }
        }
        
        if(idx==-1)
        {
            return false;
        }
        
        bool left=checktree(pre+1,in,post,idx);
        
        bool right=checktree(pre+idx+1,in+idx+1,post+idx,n-idx-1);
        
        return (left and right);
    	// Your code goes here
    } 

};
