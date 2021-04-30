string MostFrequent(string para, vector<string> tab) 
{
    unordered_map<string,int>mp;
    vector<string>kemp;
    string temp;
    for(int i=0;i<para.size();i++)
    {
        if((para[i]>='a' and para[i]<='z') or (para[i]>='A' and para[i]<='Z'))
        {
            temp.push_back(para[i]);
        }
        else
        {
            if(temp!="")
            {
                transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                mp[temp]++;
                temp.clear();
            }
        }
    }
    
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    mp[temp]++;
    temp.clear();
    
    for(auto x:tab)
    {
        mp[x]=0;
    }
    
    string ans;
    int f=INT_MIN;
    for(auto x:mp)
    {
        if(x.second>f)
        {
            ans=x.first;
            f=x.second;
        }
    }
    return ans;
    // Your Code
}
