class Solution {
public:
    vector<vector<string>>ans;
    
    void dfs(string s,string e,unordered_map<string,unordered_set<string>>&mp,vector<string>&path)
    {
        path.push_back(s);
        if(s==e)
        {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        
        for(auto x:mp[s])
        {
            dfs(x,e,mp,path);
        }
        path.pop_back();
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_map<string,unordered_set<string>>mp;
        unordered_set<string>st(wordList.begin(),wordList.end());
        
        queue<string>q;
        unordered_map<string,int>vis;
        q.push(beginWord);
        vis[beginWord]=0;
        
        while(!q.empty())
        {
            string curr=q.front();
            q.pop();
            
            for(int i=0;i<curr.size();i++)
            {
                string temp=curr;
                for(char j='a';j<='z';j++)
                {
                    if(temp[i]==j)
                    {
                        continue;
                    }
                    temp[i]=j;
                    if(st.find(temp)!=st.end())
                    {
                        if(vis.find(temp)==vis.end())
                        {
                            vis[temp]=vis[curr]+1;
                            q.push(temp);
                            mp[curr].insert(temp);
                        }
                        else if(vis[temp]==vis[curr]+1)
                        {
                            mp[curr].insert(temp);
                        }
                    }
                }
            }
        }
        vector<string>path;
        dfs(beginWord,endWord,mp,path);
        return ans;
    }
};
