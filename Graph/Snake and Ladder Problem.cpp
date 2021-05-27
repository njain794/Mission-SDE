class Solution{
public:
    int minThrow(int n, int arr[])
    {
        map<int,int>lad;
        map<int,int>snak;
        
        for(int i=0;i<2*n;i+=2)
        {
            if(arr[i]<arr[i+1])
            {
                lad[arr[i]]=arr[i+1];
            }
            else
            {
                snak[arr[i]]=snak[i+1];
            }
        }
        
        vector<int>vis(31,0);
        bool found=false;
        queue<int>q;
        vis[1]=1;
        q.push(1);
        int moves=0;
        
        while(!q.empty() and found==false)
        {
            int sz=q.size();
            while(sz--)
            {
                int pos=q.front();
                q.pop();
                for(int die=1;die<=6;die++)
                {
                    if(pos+die==30)
                    {
                        found=true;
                        break;
                    }
                    if(pos+die<=30 and lad[pos+die] and !vis[lad[pos+die]])
                    {
                        vis[lad[pos+die]]=1;
                        if(lad[pos+die]==30)
                        {
                            found=true;
                            break;
                        }
                        q.push(lad[pos+die]);
                    }
                    else if(pos+die<=30 and snak[pos+die] and !vis[snak[pos+die]])
                    {
                        vis[snak[pos+die]]=1;
                        if(snak[pos+die]==30)
                        {
                            found=true;
                            break;
                        }
                        q.push(snak[pos+die]);
                    }
                    else if(pos+die<=30 and !vis[pos+die] and !snak[pos+die] and !lad[pos+die])
                    {
                        vis[pos+die]=1;
                        if(pos+die==30)
                        {
                            found=true;
                            break;
                        }
                        q.push(pos+die);
                    }
                }
            }
            moves++;
        }
        if(!found)
        {
            return -1;
        }
        return moves;
        // code here
    }
};
