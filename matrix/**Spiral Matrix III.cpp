vector<vector<int>> spiralMatrixIII(int n, int m, int x, int y) 
    {
        vector<vector<int>>mat;

        int d = 0;
        int step=1;
        while(mat.size()<n*m){
            
            //RIGHT
            for (int i = 0; i < step; ++i)
            {
                if(x>=0 and x<n and y>=0 and y<m)
                {
                    mat.push_back({x,y});
                    d++;
                }
                y++;
            }

            //DOWN
            for (int i = 0; i < step; ++i)
            {
                if(x>=0 and x<n and y>=0 and y<m)
                {
                    mat.push_back({x,y});
                    d++;
                }
                x++;
            }
            step++;

            //LEFT
            for (int i = 0; i < step; ++i)
            {
                if(x>=0 and x<n and y>=0 and y<m)
                {
                    mat.push_back({x,y});
                    d++;
                }
                y--;
            }

            //UP
            for (int i = 0; i < step; ++i)
            {
                if(x>=0 and x<n and y>=0 and y<m)
                {
                    mat.push_back({x,y});
                    d++;
                }
                x--;
            }
            step++;
        }
        return mat;
    }
