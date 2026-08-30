// class Solution {
// public:
//     int numberOfRoutes(vector<string>& grid, int d) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> dp(n, vector<int>(m, 0));
//         for (int i = 0; i < m; i++) {
//             if (grid[n - 1][i] == '.') {
//                 dp[n - 1][i] = 1;
//             }
//         }
//         for (int i = n - 2; i >= 0; i--) {
//             for (int j = 0; j < m; j++) {
//                 if (grid[i][j] == '.') {
//                     int ans = 0;
//                     for (int k = 0; k < m; k++) {
//                         if((grid[i+1][k]=='.') && ((sqrt((pow(1,2)+pow(k-j,2)))<=d))){
//                             ans = (ans + dp[i + 1][k])%1000000007;
//                         }
//                     }
//                     dp[i][j]=(ans)%1000000007;
//                 }
//             } 
//             for (int j = 0; j < m; j++) {
//                 if (grid[i][j] == '.') {
//                     for (int k = 0; k < m; k++) {
//                         if((k!=j) && (grid[i][k]=='.') && ((sqrt((pow(k-j,2)))<=d))){
//                             dp[i][j] = (dp[i][j] + dp[i][k])%1000000007;
//                         }
//                     }
//                 }
//             } 
//         }
//     int res = 0;
//         for(int i=0; i<m; i++){
//             res+=dp[0][i];
//         }
//         return res;
//     }
// };
class Solution {
public:
    static const int MOD = 1000000007;

    int numberOfRoutes(vector<string>& grid, int d) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dp(m, 0);

        // -------------------------------------------------
        // Bottom row
        // -------------------------------------------------
        // Starting at a cell itself is one route.
        for (int j = 0; j < m; j++) {
            if (grid[n - 1][j] == '.') {
                dp[j] = 1;
            }
        }

        // On the bottom row, we can also make one
        // horizontal move to another cell.
        {
            vector<int> prefix(m + 1, 0);

            for (int j = 0; j < m; j++) {
                prefix[j + 1] = (prefix[j] + dp[j]) % MOD;
            }

            vector<int> newDp(m, 0);

            for (int j = 0; j < m; j++) {
                if (grid[n - 1][j] == '#')
                    continue;

                int L = max(0, j - d);
                int R = min(m - 1, j + d);

                // All cells in [L,R], except itself
                int sum = (prefix[R + 1] - prefix[L] + MOD) % MOD;

                newDp[j] = (sum - dp[j] + MOD) % MOD;

                // The route can also stop at this cell.
                newDp[j] = (newDp[j] + 1) % MOD;
            }

            dp = newDp;
        }

        // Maximum horizontal difference when moving
        // exactly one row down.
        int downDist = sqrt(1LL * d * d - 1);

        // -------------------------------------------------
        // Process remaining rows bottom -> top
        // -------------------------------------------------
        for (int i = n - 2; i >= 0; i--) {

            // Prefix sum of dp from the row below
            vector<int> prefix(m + 1, 0);

            for (int j = 0; j < m; j++) {
                prefix[j + 1] = (prefix[j] + dp[j]) % MOD;
            }

            vector<int> newDp(m, 0);

            // ---------------------------------------------
            // Move to the row below
            // ---------------------------------------------
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '#')
                    continue;

                int L = max(0, j - downDist);
                int R = min(m - 1, j + downDist);

                newDp[j] =
                    (prefix[R + 1] - prefix[L] + MOD) % MOD;
            }

            // ---------------------------------------------
            // Horizontal move in the same row
            // ---------------------------------------------
            prefix.assign(m + 1, 0);

            for (int j = 0; j < m; j++) {
                prefix[j + 1] =
                    (prefix[j] + newDp[j]) % MOD;
            }

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '#')
                    continue;

                int L = max(0, j - d);
                int R = min(m - 1, j + d);

                int horizontal =
                    (prefix[R + 1] - prefix[L] + MOD) % MOD;

                // Don't move from j -> j itself
                horizontal =
                    (horizontal - newDp[j] + MOD) % MOD;

                newDp[j] =
                    (newDp[j] + horizontal) % MOD;
            }

            dp = newDp;
        }

        // Every valid cell in the top row can be a starting cell.
        int ans = 0;

        for (int j = 0; j < m; j++) {
            ans = (ans + dp[j]) % MOD;
        }

        return ans;
    }
};