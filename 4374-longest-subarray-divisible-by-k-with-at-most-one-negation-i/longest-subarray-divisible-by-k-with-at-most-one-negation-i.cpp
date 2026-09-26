class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        // unordered_map<int,int> m;
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> m;
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if ((sum % k == 0) || ((sum - 2 * nums[j]) % k == 0)) {
                    ans = max(ans, j - i + 1);
                } else {
                    for (auto it : m) {
                        if ((sum - 2 * it.first) % k == 0) {
                            ans = max(ans, j - i + 1);
                            break;
                        }
                    }
                }
                // (((sum-2*(sum%k))%k)==0 && m.find(2*(sum%k))!=m.end())
                m[nums[j]]++;
            }
        }
        return ans;
    }
};