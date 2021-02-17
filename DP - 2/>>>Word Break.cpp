int wordBreak(string s, vector<string> &dict) 
{
int len=s.length();
    int dp[len+1];
    
    dp[0]=1;
    for(int i=1;i<=len;i++)
    {
        dp[i]=0;
    }
    
    for(int i=1;i<=len;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(find(dict.begin(),dict.end(),s.substr(i-j,j))!=dict.end() && dp[i-j])
            {
                dp[i]=1;
                break;
            }
        }
    }
    return dp[len];
    }
    
