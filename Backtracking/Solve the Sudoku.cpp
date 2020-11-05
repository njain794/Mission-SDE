bool canplace(int grid[N][N],int i,int j,int n,int number)
{
    for(int x=0;x<N;x++)
    {
        if(grid[x][j]==number or grid[i][x]==number)
        {
            return false;
        }
    }
    int rn=sqrt(N);
    int sx=(i/rn)*rn;
    int sy=(j/rn)*rn;
    
    for(int a=sx;a<sx+rn;a++)
    {
        for(int b=sy;b<sy+rn;b++)
        {
            if(grid[a][b]==number)
            {
                return false;
            }
        }
    }
    return true;
}
bool solve(int grid[N][N],int i,int j,int n)
{
    if(i==N)
    {
        //printGrid(grid);
        return true;
    }
    if(j==N)
    {
        return solve(grid,i+1,0,n);
    }
    if(grid[i][j]!=0)
    {
        return solve(grid,i,j+1,n);
    }
    else
    {
        for(int number=1;number<=N;number++)
        {
            if(canplace(grid,i,j,n,number))
            {
                grid[i][j]=number;
                if(solve(grid,i,j+1,n))
                {
                    return true;
                }
                grid[i][j]=0;
            }
        }
    }
    //grid[i][j]=0;
    return false;
}

bool SolveSudoku(int grid[N][N])  
{ 
    int i=0;
    int j=0;
    return solve(grid,i,j,N);
    // Your code here
}

void printGrid (int grid[N][N]) 
{
    for(int s=0;s<N;s++)
    {
        for(int d=0;d<N;d++)
        {
            cout<<grid[s][d]<<" ";
        }
        //cout<<"\n";
    }
    // Your code here 
}
