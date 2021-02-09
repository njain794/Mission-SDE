class Solution{
public:
    
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) 
	{
	    int index=m-1;
	    int mx=-1;
	   
	    for(int i=0;i<n;i++)
	    {
	        while(index>=0 and arr[i][index]==1)
	        {
	            index--;
	            mx=i;
	        }
	    }
	    return mx;
	    // code here
	}

};
