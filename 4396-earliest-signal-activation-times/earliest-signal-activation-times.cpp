// class Solution {
// public:
//     vector<long long> ans;
//     vector<int> cnt;
//     void bfs(vector<vector<pair<int,int>>> &adj, vector<int>& requiredSignals){
//         priority_queue<vector<long long>, vector<vector<long long>> , greater<vector<long long>>> pq;
//         pq.push({0,0});
//         while(!pq.empty()){
//             vector<long long> top = pq.top();
//             long long v = top[1];
//             long long w = top[0];
//             pq.pop();
//             for(auto it : adj[v]){
//                 cnt[it.second]++;
//                 if(cnt[it.second]==requiredSignals[it.second]){
//                     ans[it.second] = max(ans[it.second] ,w + it.first);
//                     pq.push({ans[it.second],it.second});
//                 }
                
//             }
//         }
//     }
//     vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
//         ans.resize(n,0);
//         cnt.resize(n,0);
//         vector<vector<pair<int,int>>> adj(n);
//         for(auto it : edges){
//             int u = it[0];
//             int v = it[1];
//             int w = it[2];
//             adj[u].push_back({w,v});
//         }
//         bfs(adj,requiredSignals);
//         for(int i=0; i<n; i++){
//             if(cnt[i]<requiredSignals[i]){
//                 ans[i]=-1;
//             }
//         }
//         ans[0]=0;
//         return ans;
//     }
// };
class Solution {
public:
    vector<long long> ans;
    vector<int> cnt;

    void bfs(vector<vector<pair<int,int>>>& adj,
             vector<int>& requiredSignals) {

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        pq.push({0, 0});

        while (!pq.empty()) {

            auto [w, v] = pq.top();
            pq.pop();

            if (ans[v] != -1) {
                continue;
            }

            cnt[v]++;

            if (v != 0 && cnt[v] < requiredSignals[v]) {
                continue;
            }

            ans[v] = w;

            for (auto it : adj[v]) {
                if (ans[it.second] == -1) {
                    pq.push({w + it.first, it.second});
                }
            }
        }
    }

    vector<long long> earliestActivationTimes(
        int n, vector<vector<int>>& edges,
        vector<int>& requiredSignals) {

        ans.assign(n, -1);
        cnt.assign(n, 0);

        vector<vector<pair<int,int>>> adj(n);

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({w, v});
        }

        bfs(adj, requiredSignals);

        return ans;
    }
};