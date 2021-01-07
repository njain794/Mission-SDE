int ExcelColumnNumber(string s)
{
    int val=0;
    int power=0;
    
    for(int i=s.size()-1;i>=0;i--)
    {
        int v=s[i]-'A'+1;
        val+=pow(26,power)*v;
        power++;
    }
    return val;
    // Your code goes here
}
