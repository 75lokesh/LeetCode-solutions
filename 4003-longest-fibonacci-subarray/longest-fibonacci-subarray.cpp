class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int index = 2;
        int ans = 2;
        while (index < n) {
            if (nums[index - 1] + nums[index - 2] == nums[index]) {
                int len = 2;
                while ((index < n) &&
                       (nums[index - 1] + nums[index - 2] == nums[index])) {
                    len++;
                    index++;
                }
                ans = max(ans, len);
            } else {
                index++;
            }
        }
       
        return ans;
    }
};