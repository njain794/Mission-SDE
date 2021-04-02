void pows(string s,string op,vector<string>&st)
{
    if(s.length()==0)
    {
        st.push_back(op);
        return;
    }
    pows(s.substr(1),op+s[0],st);
    pows(s.substr(1),op,st);
}
vector<string> powerSet(string s)
{
    vector<string>st;
    string op="";
    pows(s,op,st);
    sort(st.begin(),st.end());
    return st;
}
