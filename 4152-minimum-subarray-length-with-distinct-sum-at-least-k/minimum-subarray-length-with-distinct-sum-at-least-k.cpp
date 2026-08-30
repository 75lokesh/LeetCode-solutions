class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int len = INT_MAX;
        unordered_map<int, int> pres;
        while (left < n && right < n) {
            while ((sum < k) && (right < n)) {
                if (pres[nums[right]] == 0) {
                    sum += nums[right];
                }
                pres[nums[right]]++;
                right++;
            }
            if (sum >= k) {
                len = min(len, right - left);
            }
            while ((sum >= k) && (left < n) && (right < n)) {
                if (pres[nums[left]] == 1) {
                    sum -= nums[left];
                }
                if (pres[nums[left]] != 0) {
                    pres[nums[left]]--;
                }
                left++;
                if (sum >= k) {
                    len = min(len, right - left);
                }
            }
        }
        while ((sum >= k) && (left < n) ) {
                if (pres[nums[left]] == 1) {
                    sum -= nums[left];
                }
                if (pres[nums[left]] != 0) {
                    pres[nums[left]]--;
                }
                left++;
                if (sum >= k) {
                    len = min(len, right - left);
                }
            }
        if (len == INT_MAX) {
            return -1;
        }
        return len;
    }
};