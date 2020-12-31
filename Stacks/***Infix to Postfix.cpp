// The main function to convert infix expression
//to postfix expression
int prec(char op)
{
    switch(op)
    {
        case '^':
            return 3;
            break;
        case '/':
            return 2;
            break;
        case '*':
            return 2;
            break;
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        default:
            return -1;
    }
}
string infixToPostfix(string s)
{
    stack<char>st;
    string ans;
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i]<='z' and s[i]>='a' or s[i]<='Z' and s[i]>='A')
        {
            ans+=s[i];
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!st.empty() and st.top()!='(')
            {
                char c=st.top();
                ans+=c;
                st.pop();
            }
            if(st.top()=='(')
            {
                st.pop();
            }
        }
        else
        {
            while(!st.empty() and prec(s[i])<=prec(st.top()))
            {
                char c=st.top();
                ans+=c;
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        char c=st.top();
        ans+=c;
        st.pop();
    }
    return ans;
    // Your code here
}
