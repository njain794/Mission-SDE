int minimumDays(int s, int n, int m)
    {
        if(n<m)
        {
            return -1;
        }
        if(n*(s-(s/7))<s*m)
        {
            return -1;
        }
        double total = s*m;
        return ceil(total/n);
}
