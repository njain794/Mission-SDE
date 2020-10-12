string find(string s) 
{
    unordered_map<char,int>mp;
    for(int i=0;i<s.size();i++)
    {
        mp[s[i]]++;
    }
    string res="";
    string ser=to_string(-1);
    for(int i=0;i<s.size();i++)
    {
        if(mp[s[i]]==1)
        {
            res+=s[i];
            return res;
        }
    }
    return ser;
    //code here
}
