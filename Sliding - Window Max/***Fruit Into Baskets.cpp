class Solution {
public:
    int totalFruit(vector<int>& tree) 
    {
        unordered_map<int,int>mp;
        int i=0,j=0;
        int n=tree.size();
        int res=INT_MIN;
        while(j<n)
        {
            mp[tree[j]]++;
            /*if(mp.size()<2)
            {
                j++;
            }*/
            if(mp.size()<=2)
            {
                res=max(res,j-i+1);
                j++;
            }
            else
            {
                while(mp.size()>2)
                {
                    mp[tree[i]]--;
                    if(mp[tree[i]]==0)
                    {
                        mp.erase(tree[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        if(res==INT_MIN)
        {
            return 1;
        }
        return res;
        
    }
};
