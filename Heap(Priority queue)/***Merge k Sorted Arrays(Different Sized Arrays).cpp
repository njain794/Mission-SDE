vector<int> mergeKArrays(vector<vector<int> > arr)
{
    vector<int> output;
 
    // Create a min heap with k heap nodes. Every
    // heap node has first element of an array
    priority_queue<ppi, vector<ppi>, greater<ppi> > pq;
 
    for (int i = 0; i < arr.size(); i++)
        pq.push({ arr[i][0], { i, 0 } });
 
    // Now one by one get the minimum element
    // from min heap and replace it with next
    // element of its array
    while (pq.empty() == false) {
        ppi curr = pq.top();
        pq.pop();
 
        // i ==> Array Number
        // j ==> Index in the array number
        int i = curr.second.first;
        int j = curr.second.second;
 
        output.push_back(curr.first);
 
        // The next element belongs to same array as
        // current.
        if (j + 1 < arr[i].size())
            pq.push({ arr[i][j + 1], { i, j + 1 } });
    }
 
    return output;
}
