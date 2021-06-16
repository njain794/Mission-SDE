class Solution {
  public:
	void shortest_distance(vector<vector<int>>&mat)
	{
	    int n = mat.size();
	    
	    for(int k=0;k<n;k++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                if(mat[i][k]==-1 or mat[k][j]==-1)
	                {
	                    continue;
	                }
	                if(mat[i][j]==-1)
	                {
	                    mat[i][j]=mat[i][k]+mat[k][j];
	                }
	                else
	                {
	                    mat[i][j]=min(mat[i][j],(mat[i][k]+mat[k][j]));
	                }
	            }
	        }
	    }
	    // Code here
	}
};
