class Solution{   
public:
    int median(vector<vector<int>> &mat, int r, int c)
    {
        int mn=INT_MAX;
        int mx=INT_MIN;
        
        for(int i=0;i<r;i++)
        {
            mn=min(mn,mat[i][0]);
            mx=max(mx,mat[i][c-1]);
        }
        // code here  
        int desired=(1+(r*c))/2;
        while(mn<mx)
        {
        int count=0;
        int mid=(mn+(mx-mn)/2);
        for(int i=0;i<r;i++)
        {
            count+=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
        }
        if(count<desired)
        {
            mn=mid+1;
        }
        else
        {
            mx=mid;
        }
        //return mn;
    }
    return mn;
    }
};
