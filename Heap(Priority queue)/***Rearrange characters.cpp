string rearrangeString(string str)
{
      string rts;
      map<char,int>mp;
      priority_queue<pair<int,char>>maxh;
      
      for(int i=0;i<str.size();i++)
      {
          mp[str[i]]++;
      }
      for(auto x:mp)
      {
          maxh.push({x.second,x.first});
      }
      
      while(!maxh.empty())
      {
          pair<int,char>p=maxh.top();
          maxh.pop();
          if(p.first>0)
          {
              rts.push_back(p.second);
              p.first-=1;
          }
          if(!maxh.empty())
          {
              pair<int,char>p2=maxh.top();
              maxh.pop();
              if(p2.first>0)
              {
                  rts.push_back(p2.second);
                  p2.first-=1;
              }
              if(p2.first>0)
              {
                maxh.push(p2);
              }
              
          }
          if(p.first>0)
          {
              maxh.push(p);
          }
      }
      //cout<<rts<<"\n";
      if(rts.size()==str.size())
      {
          return rts;
      }
      else
      {
        return "aa";
      }    
	// Your code here
}
