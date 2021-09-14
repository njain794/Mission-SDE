int n=s.size();
    if(n&1)
    {
        return -1;
    }

    int c1=0;
    int c2=0;
    stack<char>st;

    for(int i=0;i<n;i++)
    {
        if(s[i]=='{')
        {
            st.push(s[i]);
            c1++;
        }
        else if(s[i]=='}' and !st.empty() and st.top()=='{')
        {
            st.pop();
            c1--;
        }
        else
        {
            c2++;
        }
    }

    int a=(c1&1)?(c1/2)+1:c1/2;
    int b=(c2&1)?(c2/2)+1:c2/2;
    return a+b;
