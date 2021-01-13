class Solution {
private:
public:
    bool sorto(const pair<int,int>&a,const pair<int,int>&b)
    {
        return (a.first<b.first);
    }
	int minSwaps(vector<int>&num)
	{
	    vector<pair<int,int>>v1,v2;
	    for(int i=0;i<num.size();i++)
	    {
	        v1.push_back(make_pair(num[i],i));
	        v2.push_back(make_pair(num[i],i));
	    }
	    sort(v2.begin(),v2.end());
	    int count=0;
	    for(int i=0;i<num.size();i++)
	    {
	        pair<int,int>p1=v2[i];
	        if(p1.second!=i)
	        {
	            pair<int,int>p2=v1[i];
	            swap(v2[p1.second],v2[p2.second]);
	            count++;
	            i--;
	        }
	    }
	    return count;
	    // Code here
	}
};
