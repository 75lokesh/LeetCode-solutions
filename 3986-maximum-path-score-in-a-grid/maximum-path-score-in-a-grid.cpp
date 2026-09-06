class Solution {
public:
    int solve(vector<vector<int>>& grid, int x, int y, int n, int m, int k,
              int cost, int score, vector<vector<vector<int>>>& dp) {
        if (cost > k) {
            return INT_MIN;
        }
        if ((cost <= k) && (x == n - 1) && (y == m - 1)) {
            return 0;
        }
        if (dp[x][y][cost] != -1) {
            return dp[x][y][cost];
        }
        int temp = INT_MIN;
        if (x < n - 1) {
            if (grid[x + 1][y] == 0 || grid[x + 1][y] == 1) {
                temp = max(temp,
                           grid[x+1][y]+solve(grid, x + 1, y, n, m, k, cost + grid[x + 1][y],
                                 score + grid[x + 1][y], dp));
            } else if (grid[x + 1][y] == 2) {
                temp = max(temp, grid[x+1][y] + solve(grid, x + 1, y, n, m, k, cost + 1,
                                       score + grid[x + 1][y], dp));
            }
        }
        if (y < m - 1) {
            if (grid[x][y + 1] == 0 || grid[x][y + 1] == 1) {
                temp = max(temp,
                           grid[x][y+1] + solve(grid, x, y + 1, n, m, k, cost + grid[x][y + 1],
                                 score + grid[x][y + 1], dp));
            } else if (grid[x][y + 1] == 2) {
                temp = max(temp, grid[x][y+1] + solve(grid, x, y + 1, n, m, k, cost + 1,
                                       score + grid[x][y + 1], dp));
            }
        }
       return dp[x][y][cost]=temp;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int score = grid[0][0];
        int cost = min(1,grid[0][0]);
        int ans = grid[0][0] + solve(grid,0,0,n,m,k,cost,score,dp);
        if(ans<0){
            return -1;
        }
        return ans;
    }
};