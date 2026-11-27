class Solution {
public:
    long long minCost(vector<int>& nums) {
        int left = 1;
        long long ans = LLONG_MAX;
        int n = nums.size();
        unordered_map<int, int> pref;
        unordered_map<int, int> suff;
        // for (int i = 1; i < n; i++) {
        //     if (pref.find(nums[i]) == pref.end()) {
        //         pref[nums[i]] = i;
        //     }
        // }
        // for (int i = 1; i < n; i++) {
        //     if (suff.find(nums[i]) == suff.end() && (i < n - 1) &&
        //         (nums[i] != nums[i + 1])) {
        //         suff[nums[i]] = i;
        //     } else if (suff.find(nums[i]) == suff.end() && (i == n - 1)) {
        //         suff[nums[i]] = i;
        //     }
        // }
        int tleft = 1;
        while (tleft < n) {
            int start = nums[tleft];
            int s = tleft;
            while ((tleft < n) && start == nums[tleft]) {
                tleft++;
            }
            if (pref.find(start) != pref.end() &&
                (tleft - s > suff[start] - pref[start] + 1)) {
                pref[start] = s;
                suff[start] = tleft - 1;
            } else if (pref.find(start) == pref.end()) {
                pref[start] = s;
                suff[start] = tleft - 1;
            }
        }
        while (left < n - 1) {
            long long temp = 0;
            if (pref[nums[left]] == 1 && nums[left] == nums[0]) {
                temp = 1LL * (pref[nums[left]] - 1) * nums[left] +
                       1LL * (n - suff[nums[left]] - 1) * nums[left];
            } else {
                temp = 1LL * pref[nums[left]] * nums[left] +
                       1LL * (n - suff[nums[left]] - 1) * nums[left];
            }

            ans = min(ans, temp);
            left++;
        }
        return ans;
    }
};