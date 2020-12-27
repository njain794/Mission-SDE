//https://practice.geeksforgeeks.org/problems/minimum-vertical-sum/1/?track=CPP-STL-Sequenced-Containers&batchId=185#

int minimum_vertical_sum(vector<vector<int>>v)
{
    vector<int>res;
    for(int i=0;i<v.size();i++)
    {
        //int sum=0;
        for(int j=0;j<v[i].size();j++)
        {
            if(j>=res.size())
            {
                res.push_back(v[i][j]);
            }
            else
            {
                res[j]+=v[i][j];
            }    
        }
    }
    auto it=min_element(res.begin(),res.end());
    return *it;
    //Your code here
}
