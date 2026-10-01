// class Solution {
// public:
//     bool ispalindrom(string str) {
//         int left = 0;
//         int right = str.size() - 1;
//         while (left < right) {
//             if (str[left] != str[right]) {
//                 return false;
//             }
//             left++;
//             right--;
//         }
//         return true;
//     }
//     void dfs(vector<vector<int>>& adjlist, int node, string str, int& len,
//              vector<bool> vis, string& label) {
//         if (ispalindrom(str)) {
//             len = max(len, (int)str.size());
//         }
//         // vis[node] = 1;
//         for (auto nbr : adjlist[node]) {

//             if (!vis[nbr]) {
//                 vis[nbr] = 1;
//                 dfs(adjlist, nbr, str + label[nbr], len, vis, label);
//                 vis[nbr] = 0;
//             }
//              if (!vis[nbr]) {
//                 vis[nbr] = true;

//                 dfs(adjlist, nbr,
//                     str + label[nbr],
//                     len, vis, label);

//                 vis[nbr] = false;
//             }
//         }
//         // vis[node] = 0;
//         return ;
//     }
//     int maxLen(int n, vector<vector<int>>& edges, string label) {
//         vector<vector<int>> adjlist(n);
//         // vector<int> indegree(n, 0);
//         int m = edges.size();
//         for (int i = 0; i < m; i++) {
//             int u = edges[i][0];
//             int v = edges[i][1];

//             adjlist[u].push_back(v);
//             adjlist[v].push_back(u);
//         }
//         int len = 0;
//          vector<bool> vis(n, 0);
//         for (int i = 0; i < n; i++) {
//             int templen = 0;
//             vis[i]=1;
//             dfs(adjlist, i, string(1,label[i]), templen, vis, label);
//             vis[i] =0;
//             len = max(templen, len);
//         }
//         return len;
//     }
// };
class Solution {
public:
    vector<vector<int>> adj;
    string label;

    // Returns the maximum number of additional nodes
    // that can be added outside the current pair (u, v).
    int dfs(int u, int v, int mask,
            vector<vector<vector<int>>>& dp) {

        int &res = dp[u][v][mask];

        if (res != -1)
            return res;

        res = 0;

        for (int nu : adj[u]) {

            // Already used
            if (mask & (1 << nu))
                continue;

            for (int nv : adj[v]) {

                // Already used
                if (mask & (1 << nv))
                    continue;

                // Cannot use same node on both sides
                if (nu == nv)
                    continue;

                // Characters must match
                if (label[nu] != label[nv])
                    continue;

                int newMask = mask | (1 << nu) | (1 << nv);

                res = max(res,
                          2 + dfs(nu, nv, newMask, dp));
            }
        }

        return res;
    }

    int maxLen(int n, vector<vector<int>>& edges, string s) {

        label = s;

        adj.assign(n, {});

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int totalStates = 1 << n;

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(
                n,
                vector<int>(totalStates, -1)
            )
        );

        int ans = 1;

        // -------------------------
        // Odd length palindrome
        // -------------------------
        // Center = u
        //
        // Example:
        //      j
        //      |
        //      h
        //      |
        //      j
        //
        // dfs(u,u,...)
        //
        for (int u = 0; u < n; u++) {

            int mask = 1 << u;

            ans = max(
                ans,
                1 + dfs(u, u, mask, dp)
            );
        }

        // -------------------------
        // Even length palindrome
        // -------------------------
        // Center = edge (u,v)
        //
        // labels must be equal
        //
        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];

            if (label[u] != label[v])
                continue;

            int mask = (1 << u) | (1 << v);

            ans = max(
                ans,
                2 + dfs(u, v, mask, dp)
            );
        }

        return ans;
    }
};