int countWays(int n, int m)
	    {
	        if(n<m)
	        {
	            return 1;
	        }
	        else
	        {
	            return (countWays(n-1,m) + countWays(n-m,m));
	        }
      }    
