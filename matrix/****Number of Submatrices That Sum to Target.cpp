class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int result = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> preSum(m, vector<int>(n + 1));
        for(int i = 0; i < m; i++){
            for(int j = 1; j <= n; j++){
                preSum[i][j] += preSum[i][j - 1] + matrix[i][j - 1];
            }
        }
        
        unordered_map<int, int> map;
        for(int startCol = 1; startCol <= n; startCol++){
            for(int endCol = startCol; endCol <= n; endCol++){
                map.clear();
                map[0] = 1;
                int curSum = 0;
                for(int row = 0; row < m; row++){
                    curSum += preSum[row][endCol] - preSum[row][startCol - 1];
                   
                    if(map.find(curSum - target) != map.end()){
                        result += map[curSum - target];
                    }
                    map[curSum]++;
                }
            }
        }
        return result;
    }
};

//The idea is similar to P560 Subarray sum equals K
