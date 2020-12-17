void permute(string s,string ans,vector<string> &v)
{
    if(s.length()==0)
    {
        v.push_back(ans);
        //cout<<ans<<" ";
        return;
    }
    
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        string ros=s.substr(0,i)+s.substr(i+1);
        permute(ros,ans+ch,v);
    }
}
int RankMe(string str)
{
    vector<string>out;
    string ans="";
    permute(str,ans,out);
    
    sort(out.begin(),out.end());
    /*for(int i=0;i<out.size();i++)
    {
        cout<<out[i]<<" ";
    }*/
    for(int i=0;i<out.size();i++)
    {
        if(str==out[i])
        {
            return (i+1);
        }
    }
	 // Your code here
    // Use next_permutation function
    
}
