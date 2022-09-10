int isStackPermutation(int N,vector<int> &A,vector<int> &B)
    {
         stack<int> st;
       
       int aind = 0;
       int bind = 0;
       
       while(aind < N){
           
           if(!st.empty() && (st.top() == B[bind])){
               bind++;
               st.pop();
           }else{
               st.push(A[aind]);
               aind++;
           }
       }
       while(!st.empty() && st.top()==B[bind])
        {
            bind++;
            st.pop();
        }
       if(aind==bind)
           return 1;
       else
           return 0;
   }
