string largestNumber(int n, int sum)
    {
        if(sum>(9*n))
        {
            return "-1";
        }
        else
        {
            string temp="";
            for(int i=0;i<n;i++)
            {
                if(sum!=0)
                {
                    if(sum>9)
                    {
                        temp.push_back('9');
                        sum-=9;
                    }
                    else
                    {
                        string kemp=to_string(sum);
                        temp+=kemp;
                        sum=0;
                    }
                }
                else
                {
                    temp.push_back('0');
                }
            }
            return temp;
        }
    
