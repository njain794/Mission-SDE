class TicTacToe {
public:
    /** Initialize your data structure here. */
    int *r,*c,d1,d2,s;
    TicTacToe(int n) {
        r=new int[n];
        c=new int[n];
        d1=0;
        d2=0;
        s=n;
    }
    int move(int row, int col,int p) 
    {
        if(p==1)
        {
            r[row]++;
            c[col]++;
            if(row==col)
            {
                d1++;
            }
            if(row+col==s-1)
            {
                d2++;
            }
            if(r[row]==s or c[col]==s or d1==s or d2==s)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        } 
        else
        {
            r[row]--;
            c[col]--;
            if(row==col)
            {
                d1--;
            }
            if(row+col==s-1)
            {
                d2--;
            }
            int k=(-1*s);
            if(r[row]==k or c[col]==k or d1==k or d2==k)
            {
                return 2;
            }
            else{
                return 0;
            }
        }  
    }
};
