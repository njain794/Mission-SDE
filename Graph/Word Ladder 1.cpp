https://practice.geeksforgeeks.org/viewSol.php?subId=1a3918c0e2743066e874dd07f18f724f&pid=701841&user=namanjain41

class Solution {
public:
    int wordLadderLength(string start, string target, vector<string>& wordlist) 
    {
        queue<string> q;
        q.push(start);
        
        unordered_set<string>st;
        for(auto word:wordlist)
        {
            st.insert(word);
        }
        
        if(start==target)
        {
            return 0;
        }
        
        if(st.find(target)==st.end())
        {
            return 0;
        }
        
        int steps=0;
        
        while(!q.empty())
        {
            steps++;
            int len=q.size();
            while(len--)
            {
                string s=q.front();
                q.pop();
                
                for(int i=0;i<s.size();i++)
                {
                    char temp=s[i];
                    for(char j='a';j<='z';j++)
                    {
                        s[i]=j;
                        if(s==target)
                        {
                            return steps+1;
                        }
                        if(st.find(s)==st.end())
                        {
                            continue;
                        }
                        st.erase(s);
                        q.push(s);
                    }
                    s[i]=temp;
                }
                
                
            }
        }
        return 0;
        // Code here
    }
};
