/*
You are given a vector v of n size. You need to sort the vector and print the vector in a specific order as mentioned in the sample example.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line contains n denoting the size of vector v. The second line contains the elements to be inserted in the vector.

Output Format:
For each testcase, in a new line, print the output as mentioned.

Your Task:
This is a function problem. You only need to complete the function thePendulum() that takes a vector as a parameter and returns the modified vector. The printing is done by the driver code.

Constraints:
1 <= T <= 100
1 <= n <= 100
1 <= v[i] <= 1000

Sample Input:
2
5
5 4 3 2 1
4
4 1 2 3

Sample Output:
5 2 1 3 4
2 1 3 4

Explanation:
Testcase1: When we sort it we get 1 2 3 4 5. Now, we need to insert pair of two elements according 
to the motion of a pendulum from left to right. So if we assume a stable | in the middle then the 
first 2 elements get inserted from the left so answer becomes 2 1 | Now the next two elements are 
inserted from right, so answer becomes 2 1 | 3 4, Now there is only 1 element left so we pick that 
and insert it from left so answer becomes 5 2 1 | 3 4. The final answer thus is 5 2 1 3 4.
*/
vector<int> thePendulum(vector<int>v)
{
    int dir=1;
    list<int>l;
    vector<int>ans;
    sort(v.begin(),v.end());
    
    for(int i=0;i<v.size();)
    {
        if(dir==1)
        {
            l.push_front(v[i]);
            i++;
            if(i<v.size())
            {
                l.push_front(v[i]);
                i++;
            }
            dir=2;
        }
        else
        {
            l.push_back(v[i]);
            i++;
            if(i<v.size())
            {
                l.push_back(v[i]);
                i++;
            }
            dir=1;
        }
    }
    
    for(auto itr=l.begin();itr!=l.end();itr++)
    {
        ans.push_back(*itr);
    }
    return ans;
    //Your code here
}
