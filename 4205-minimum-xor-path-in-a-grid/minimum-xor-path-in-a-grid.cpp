// class Solution {
// public:
//     void solve(vector<vector<int>> &grid, int row, int col, int n, int m, long long &ans, long long mult){
//         if((row==n-1) && (col == m-1)){
//             ans= min(ans,mult);
//             return;
//         }
//         if(row+1<n){
//          solve(grid,row+1,col,n,m, ans, mult^grid[row+1][col]);}
//         if(col+1<m){
//          solve(grid,row,col+1,n,m, ans, mult^grid[row][col+1]);}
//     }
//     int minCost(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         long long ans = INT_MAX;
//         long long mult = grid[0][0];
//         solve(grid,0,0,n,m,ans,mult);
//         return ans;
//     }
// };
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        const int MAXX = 1024;

        vector<vector<vector<bool>>> dp(
            n, vector<vector<bool>>(m, vector<bool>(MAXX, false))
        );

        dp[0][0][grid[0][0]] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i == 0 && j == 0)
                    continue;

                if (i > 0) {
                    for (int x = 0; x < MAXX; x++) {
                        if (dp[i - 1][j][x]) {
                            dp[i][j][x ^ grid[i][j]] = true;
                        }
                    }
                }

                if (j > 0) {
                    for (int x = 0; x < MAXX; x++) {
                        if (dp[i][j - 1][x]) {
                            dp[i][j][x ^ grid[i][j]] = true;
                        }
                    }
                }
            }
        }

        for (int x = 0; x < MAXX; x++) {
            if (dp[n - 1][m - 1][x])
                return x;
        }

        return -1;
    }
};