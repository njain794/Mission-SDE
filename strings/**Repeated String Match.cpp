// https://practice.geeksforgeeks.org/problems/0cba668df04d657fde4d1bd28b626a01e61097f1/1/?track=30-DOC-day-10&batchId=320#
class Solution{

    public:
    int repeatedStringMatch(string a, string b) 
    {
        int count = (b.size()/a.size());
        int res=1;
        string str=a;
        
        for(int i=0;i<=count+2;i++)
        {
            if(str.find(b)!=string::npos)
            {
                return res;
            }
            else
            {
                str+=a;
                res++;
            }    
        }
        
        return -1;
        // Your code goes here
    }
  
};
