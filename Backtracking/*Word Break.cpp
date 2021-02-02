bool solve(int i,int j,string &temp,vector<string>&v)
{
    if(j==temp.size())
    {
        if(i==temp.size())
        {
            return true;
        }
        return false;
    }
    
    if(find(v.begin(),v.end(),temp.substr(i,j-i+1))==v.end())
    {
        return solve(i,j+1,temp,v);
    }
    else
    {
        return(solve(i,j+1,temp,v) or solve(j+1,j+1,temp,v));
        /*if(solve(i,j+1,temp,v))
        {
            return true;
        }
        else
        {
            return solve(j+1,j+1,temp,v);
        }*/
    }
    
}

int wordBreak(string A, vector<string> &B) 
{
    if(solve(0,0,A,B))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    //code here
}
