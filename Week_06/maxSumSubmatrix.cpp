class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        if (rows == 0 ) return 0;
        int cols = matrix[0].size();
        if (cols == 0 ) return 0;

        int res = -INT_MAX;
        int DP[rows+1][cols+1];

        for (int i = 0; i < rows + 1; i++) DP[i][0] = 0;
        
        for (int j = 0; j < cols + 1; j++) DP[0][j] = 0;
    
        for (int i = 1 ; i < rows + 1; i++){
            for (int j = 1 ; j < cols + 1; j++)DP[i][j] = DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1] + matrix[i-1][j-1];}

        for (int i1 = 0 ; i1 < rows; i1++){
            for (int i2 = i1+1 ; i2 <= rows; i2++){
                for (int j1 = 0; j1 < cols; j1++){
                    for (int j2 = j1+1;  j2 <= cols; j2++){
                        int total =  DP[i2][j2] - DP[i2][j1] - DP[i1][j2]  + DP[i1][j1];
                       
                        if (total == k) return total;
                        if ( total <k ) res = max(total,res);
                    }
                }
            }
        }
        return res;
    }
};
