https://practice.geeksforgeeks.org/viewSol.php?subId=1a3918c0e2743066e874dd07f18f724f&pid=701841&user=namanjain41

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string>st;
        bool flag=false;
        
        for(auto x:wordList)
        {
            if(x==endWord)
            {
                flag=true;
            }
            st.insert(x);
        }
        
        if(flag==false)
        {
            return 0;
        }
        
        queue<string>q;
        q.push(beginWord);
        int depth=0;
        
        while(!q.empty())
        {
            depth++;
            int sz=q.size();
            while(sz--)
            {
                string curr=q.front();
                q.pop();
                
                for(int i=0;i<curr.size();i++)
                {
                    string temp=curr;
                    for(char j='a';j<='z';j++)
                    {
                        temp[i]=j;
                        if(temp==curr)
                        {
                            continue;
                        }
                        else if(temp==endWord)
                        {
                            return depth+1;
                        }
                        else
                        {
                            if(st.find(temp)!=st.end())
                            {
                                q.push(temp);
                                st.erase(temp);
                            }
                        }
                    }
                }
            }
        }
        return 0;   
    }
};
