class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            res[0][j] = matrix[0][j] - '0';
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    res[i][j] = res[i - 1][j] + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int L = j;
                int index = j;
                while ((index-1 >= 0) && (res[i][index - 1] >= res[i][j])) {
                    L = index-1;
                    index--;
                }
                index = j;
                int R = j;
                while ((index+1 < m) && (res[i][index + 1] >= res[i][j])) {
                    R = index+1;
                    index++;
                }
                int temp = min(res[i][j],R-L+1);
                ans = max(ans, temp * temp);
            }
        }
        return ans;
    }
};