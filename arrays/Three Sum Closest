int threeSumClosest(vector<int> v, int target) 
{
   sort(v.begin(),v.end());
   int n=v.size();
   int res=INT_MAX;
   for(int i=0;i<n-2;i++)
   {
        //int sum = target-v[i];
        int s=i+1;
        int d=n-1;
        while(s<d)
        {
            int out=v[s]+v[d]+v[i];
            if(abs(out-target)<abs(res-target))
            {
                res=out;
            }
            if(out==target)
            {
                return out;
            }
            if(abs(out-target)==abs(res-target))
            {
                if(out>res)
                {
                    res=out;
                }
            }
            if(out>target)
            {
                d--;
            }
            else if(out<target)
            {
                s++;
            }
        }
   }
   return res;
}
