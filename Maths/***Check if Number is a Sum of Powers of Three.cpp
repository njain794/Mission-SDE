bool checkPowersOfThree(int n) 
    {
        while(n>0 and (n%3==0 or n%3==1))
        {
            n=n/3;
        }
        if(n==0)
        {
            return true;
        }
        else
        {
            return false;
        }
   }     
