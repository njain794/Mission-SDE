class Solution{
public:
    int isHappy(int n)
    {
        unordered_set<int>st;
        //flag=true;
        while(st.find(n)==st.end())
        {
            st.insert(n);
            int d=n;
            int temp=0;
            while(d>0)
            {
                temp+=pow(d%10,2);
                d=d/10;
            }
            if(temp==1)
            {
                return true;
            }
            n=temp;
        }
        return false;
        // code here
    }
};
