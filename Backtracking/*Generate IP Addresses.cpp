bool issubpart(string s,int i,int j)
{
    int len=j-i+1;
    if(len>3)
    {
        return false;
    }
    if(s[i]=='0')
    {
        if(len>1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
    int num=stoi(s.substr(i,j-i+1));
    if(num>=0 and num<=255)
    {
        return true;
    }
    return false;
}

bool isvalid(string s,int n,int i,int j,int k)
{
    if(issubpart(s,0,i) and issubpart(s,i+1,j) and issubpart(s,j+1,k) and issubpart(s,k+1,n-1))
    {
        return true;
    }
    return false;
}

void addit(string s,int n,int i,int j,int k,vector<string>&res)
{
    string temp;
    temp.append(s.substr(0,i+1));
    temp.push_back('.');
    temp.append(s.substr(i+1,j-i));
    temp.push_back('.');
    temp.append(s.substr(j+1,k-j));
    temp.push_back('.');
    temp.append(s.substr(k+1,n-k-1));
    res.push_back(temp);
}

vector<string> genIp(string &s) 
{
    int n=s.size();
    vector<string>res;
    
    for(int i=0;i<n-3;i++)
    {
        for(int j=i+1;j<n-2;j++)
        {
            for(int k=j+1;k<n-1;k++)
            {
                if(isvalid(s,n,i,j,k))
                {
                    addit(s,n,i,j,k,res);
                }
            }
        }
    }
    return res;
    // Your code here
}
