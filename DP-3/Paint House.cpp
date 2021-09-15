//#include<bits/stdc++.h>
//using namespace std;
int Solution::solve(vector<vector<int> > &mat) 
{
    int n=mat.size();

    int a=mat[0][0];
    int b=mat[0][1];
    int c=mat[0][2];

    for(int i=1;i<n;i++)
    {
        int a1=mat[i][0]+min(b,c);
        int b1=mat[i][1]+min(a,c);
        int c1=mat[i][2]+min(a,b);

        a=a1;
        b=b1;
        c=c1;
    }
    return min(a,min(b,c));

}
