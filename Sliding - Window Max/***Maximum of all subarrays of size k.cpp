vector <int> max_of_subarrays(int *arr, int n, int k)
{
    vector<int>v;
    deque<int>dq;
    int i=0,j=0;
    while(j<n)
    {
        if(j-i+1<k)
        {
            while(!dq.empty() and dq.back()<arr[j])
            {
                dq.pop_back();
            }
            dq.push_back(arr[j]);
            j++;
        }
        else if(j-i+1==k)
        {
            while(!dq.empty() and dq.back()<arr[j])
            {
                dq.pop_back();
            }
            dq.push_back(arr[j]);
            
            v.push_back(dq.front());
            if(dq.front()==arr[i])
            {
                dq.pop_front();
            }
            i++;
            j++;
        }
    }
    return v;
    // your code here
}
