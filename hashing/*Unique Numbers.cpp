class Solution
{
public:
    vector<int> uniqueNumbers(int L,int R)
    {
        vector<int>v;
        for(int i=L;i<=R;i++)
        {
            int num=i;
            bool vis[10]={false};
            
            while(num)
            {
                if(vis[num%10])
                {
                    break;
                }
                vis[num%10]=true;
                num=num/10;
            }
            
            if(num==0)
            {
                v.push_back(i);
            }
        }
        return v;
        // Write Your Code here
    }
};
