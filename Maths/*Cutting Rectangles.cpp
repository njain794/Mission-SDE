class Solution{
public:
    vector<long long int> minimumSquares(long long int l, long long int b)
    {
        vector<long long int>v(2);
        v[1] = __gcd(l,b);
        v[0] = (l/v[1])*(b/v[1]);
        return v;
        // code here
    }
};
