class Solution {
public:

    void solve(vector<vector<int>>&image,int n,int m,int sr,int sc,int oldc,int newc)
    {
        if(sr<0 or sc<0 or sr>=n or sc>=m or image[sr][sc]!=oldc)
        {
            return;
        }
        
        image[sr][sc]=newc;
        
        solve(image,n,m,sr-1,sc,oldc,newc);
        solve(image,n,m,sr+1,sc,oldc,newc);
        solve(image,n,m,sr,sc-1,oldc,newc);
        solve(image,n,m,sr,sc+1,oldc,newc);
        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor)
    {
        if(image[sr][sc]==newcolor)return image;
        
        int n=image.size();
        int m=image[0].size();
        
        int oldcolor = image[sr][sc];
        
        solve(image,n,m,sr,sc,oldcolor,newcolor);
        return image;
        // Code here 
    }
};
