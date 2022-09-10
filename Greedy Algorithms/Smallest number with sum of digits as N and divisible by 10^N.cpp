string digitsNum(int n)
	{
	    int num=n;
	    string temp;
	    while(num>9)
	    {
	        temp.push_back('9');
	        num-=9;
	    }
	    if(num>0)
	    {
	        temp+=to_string(num);
	    }
	    reverse(temp.begin(),temp.end());
	    for(int i=0;i<n;i++)
	    {
	        temp.push_back('0');
	    }
	    return temp;
	    
	}
