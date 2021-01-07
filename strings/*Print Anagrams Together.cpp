vector<vector<string> > Anagrams(vector<string>& s) 
{
    map<string,vector<string>>mp;
    for(int i=0;i<s.size();i++)
    {
        string temp=s[i];
        sort(temp.begin(),temp.end());
        mp[temp].push_back(s[i]);
    }
    vector<vector<string>>res;
    for(auto x:mp)
    {
        vector<string>kemp;
        for(auto y:x.second)
        {
            kemp.push_back(y);
        }
        res.push_back(kemp);
    }
    return res;
    // Your Code Here
}
