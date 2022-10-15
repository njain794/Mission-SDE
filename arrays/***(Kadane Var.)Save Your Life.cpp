class Solution{
public:

      string solve(string s,vector<int>v)
      {
        int start=0,a1=0,a2;
        
        int maxf=INT_MIN;
        int maxe=0;
        string maxAns="";
        string str="";
        
        for(int i=0;i<v.size();i++)
        {
            maxe+=v[i];
            str+=s[i];
            
            if(maxe>=maxf)
            {
                maxf=maxe;
                maxAns=str;
            }
            if(maxe<0)
            {
                maxe=0;
                str="";
            }
        }
        
        return maxAns;
      }

      string maxSum(string w,char x[],int b[],int n)
      {
            unordered_map<char,int>mp;
            for(int i=0;i<n;i++)
            {
                mp[x[i]]=b[i];
            }
            
            vector<int>v;
            int m=w.size();
            
            for(int i=0;i<m;i++)
            {
                char c = w[i];
                if(mp.find(c)!=mp.end())
                {
                    v.push_back(mp[c]);
                }
                else
                {
                    v.push_back((int)c);
                }
            }
            
            string ans = solve(w,v);
            return ans;
      }
};
