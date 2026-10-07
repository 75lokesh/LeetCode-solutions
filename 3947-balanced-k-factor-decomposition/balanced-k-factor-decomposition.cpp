// class Solution {
// public:
//     vector<int> primefactors(int n){       
//         vector<int> ans;
//         int temp = n;
//         for(int i=2; i<=temp; i++){
//             while((n>0) && (n%i==0)){
//                 ans.push_back(i);
//                 n=n/i;
//             }
//             if(n<=1){
//                 return ans;
//             }
//         }
//         return ans;
//     }
//     vector<int> minDifference(int n, int k) {
//         vector<int> fact = primefactors(n);
//         if(fact.size()<=k){
//             while(fact.size()<k){
//                 fact.push_back(1);
//             }
//             return fact;
//         }
//        priority_queue<int,vector<int>,greater<int>>pq;
//         for(int it : fact){
//             pq.push(it);
//         }
//         while(pq.size()>k){
//             int top1 = pq.top();
//             pq.pop();
//             int top2 = pq.top();
//             pq.pop();
//             pq.push(top1*top2);
//         }
//         vector<int> ans;
//         while(!pq.empty()){
//             ans.push_back(pq.top());
//             pq.pop();
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> ans;
    long long best = LLONG_MAX;
    int K;

    void dfs(int n, int k, int last, vector<int>& cur) {
        if (k == 1) {
            if (n < last) return;

            cur.push_back(n);

            long long mn = cur[0];
            long long mx = cur.back();

            if (mx - mn < best) {
                best = mx - mn;
                ans = cur;
            }

            cur.pop_back();
            return;
        }

        // Try divisors of n
        for (int d = last; 1LL * d * d <= n; d++) {

            if (n % d != 0)
                continue;

            cur.push_back(d);

            dfs(n / d, k - 1, d, cur);

            cur.pop_back();
        }
    }

    vector<int> minDifference(int n, int k) {
        K = k;

        vector<int> cur;

        dfs(n, k, 1, cur);

        return ans;
    }
};