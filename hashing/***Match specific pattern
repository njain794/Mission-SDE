string gen(string sd)
{
    unordered_map<char,int>mp;
    string res="";
    int i=0;
    for(auto x:sd)
    {
       if(mp.find(x)==mp.end())
       {
           mp[x]=i++;
       }
       res+=to_string(mp[x]);
    }
    return res;
}
vector<string> findMatchedWords(vector<string> dict,
                      string pattern)
{
    int n=pattern.length();
    string sd=gen(pattern);
    vector<string>out;
    
    for(auto x:dict)
    {
        if(x.length()==n and gen(x)==sd)
        {
            out.push_back(x);
        }
    }
    return out;
       //Your code here
}
