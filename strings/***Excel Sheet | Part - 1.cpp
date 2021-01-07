string ExcelColumn(int n)
{
    string t1;
    char ch='A';
    for(int i=0;i<26;i++)
    {
        //t1+=to_string(i+1);
        t1.push_back(ch++);
    }
    string ans;
    while(n>0)
    {
        int rem=n%26;
        if(rem==0)
        {
            ans.push_back('Z');
            n=(n/26)-1;
        }
        else
        {
            ans.push_back(t1[rem-1]);
            n=n/26;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
    // Your code goes here
}
