bool isAnagram(string a, string b)
{
    int count=0;
    for(int i=0;i<a.size();i++)
    {
        count+=a[i];
    }
    for(int i=0;i<b.size();i++)
    {
        count-=b[i];
    }
    if(count==0)
    {
        return true;
    }
    else
    {
        return false;
    }
    // Your code here
    
}
