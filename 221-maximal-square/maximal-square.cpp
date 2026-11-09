// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<vector<int>> res(n, vector<int>(m, 0));
//         for (int j = 0; j < m; j++) {
//             res[0][j] = matrix[0][j] - '0';
//         }
//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == '1') {
//                     res[i][j] = res[i - 1][j] + 1;
//                 }
//             }
//         }
//         int ans = 0;
//         vector<vector<int>> LEFT(n, vector<int>(m, 0));
//         vector<vector<int>> RIGHT(n, vector<int>(m, 0));
//         for (int i = 0; i < n; i++) {
//             LEFT[i][0] = 0;
//             for (int j = 1; j < m; j++) {
//                 if (res[i][LEFT[i][j - 1]] >= res[i][j]) {
//                     LEFT[i][j] = LEFT[i][j - 1];
//                 } else {
//                     LEFT[i][j] = j;
//                 }
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             RIGHT[i][m - 1] = m - 1;
//             for (int j = m - 2; j >= 0; j--) {
//                 if (res[i][RIGHT[i][j + 1]] >= res[i][j]) {
//                     RIGHT[i][j] = RIGHT[i][j + 1];
//                 } else {
//                     RIGHT[i][j] = j;
//                 }
//             }
//         }

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {

//                 int temp = min(res[i][j], RIGHT[i][j] - LEFT[i][j] + 1);
//                 ans = max(ans, temp * temp);
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();

        if (n == 0) return 0;

        int m = matrix[0].size();

        vector<int> height(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            stack<int> st;
            vector<int> left(m), right(m);

            for (int j = 0; j < m; j++) {
                while (!st.empty() && height[st.top()] >= height[j])
                    st.pop();

                left[j] = st.empty() ? -1 : st.top();
                st.push(j);
            }

            while (!st.empty()) st.pop();

            for (int j = m - 1; j >= 0; j--) {
                while (!st.empty() && height[st.top()] >= height[j])
                    st.pop();

                right[j] = st.empty() ? m : st.top();
                st.push(j);
            }

            for (int j = 0; j < m; j++) {
                int width = right[j] - left[j] - 1;

                int side = min(height[j], width);

                ans = max(ans, side * side);
            }
        }

        return ans;
    }
};