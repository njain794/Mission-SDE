class Solution {
	public:
		string LexicographicallyMinimum(string str)
		{
		    //string ctr=str;
		    if(str.size()==1)
		    {
		        return str;
		    }
		    set<char>st;
		    for(auto x:str)
		    {
		        st.insert(x);
		    }
		    
		    for(int i=0;i<str.size();i++)
		    {
		        st.erase(str[i]);
		        if(st.empty())
		        {
		            break;
		        }
		        char ch=*st.begin();
		        if(ch<str[i])
		        {
		            char ch2=str[i];
		            for(int i=0;i<str.size();i++)
		            {
		                if(str[i]==ch2)
		                {
		                    str[i]=ch;
		                }
		                else if(str[i]==ch)
		                {
		                    str[i]=ch2;
		                }
		            }
		            break;
		        }
		    }
		    return str;
		    // Code here
		}

};
