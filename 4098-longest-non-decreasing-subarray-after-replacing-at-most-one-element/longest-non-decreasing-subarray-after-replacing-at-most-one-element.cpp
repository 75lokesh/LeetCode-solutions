// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {
//         int n = nums.size();
//         int left = 0;
//         int right = 0;
//         int ans = 0;
//         int prev = nums[left];
//         int cnt = 0;
//         while(right<n){
//             while((right<n) && (((prev<=nums[right])) || (cnt<=1))){
                
//                 if((prev>nums[right])){
//                     cnt++;
//                 }
//                 else{
//                     prev = nums[right];
//                 }
//                 if(cnt==2){
//                     break;
//                 }
//                 right++;
//             }
//                ans = max(ans, right-left);
//                left=right;
//                prev=nums[right];
//                cnt = 0; 
//         }
//         left = n-1;
//         right = n-1;
//         prev = nums[left];
//         while(right>=0){
//             while((right>=0) && (((prev>=nums[right])) || (cnt<=1))){
                
//                 if((prev<nums[right])){
//                     cnt++;
//                 }
//                 else{
//                     prev = nums[right];
//                 }
//                 if(cnt==2){
//                     break;
//                 }
//                 right--;
//             }
//                ans = max(ans, left-right);
//                left=right;
//             if(right>0){
//                prev=nums[right];}
//                cnt = 0; 
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return n;

        vector<int> left(n, 1), right(n, 1);

        // left[i] = longest non-decreasing subarray ending at i
        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i - 1])
                left[i] = left[i - 1] + 1;
        }

        // right[i] = longest non-decreasing subarray starting at i
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1])
                right[i] = right[i + 1] + 1;
        }

        int ans = 1;

        // No replacement
        for (int i = 0; i < n; i++) {
            ans = max(ans, left[i]);
        }

        // Replace nums[i]
        for (int i = 0; i < n; i++) {

            // Replace first element
            if (i == 0) {
                ans = max(ans, 1 + right[1]);
            }

            // Replace last element
            else if (i == n - 1) {
                ans = max(ans, left[n - 2] + 1);
            }

            // Replace middle element
            else {
                // We can always take the left part + replaced element
                ans = max(ans, left[i - 1] + 1);

                // Or right part + replaced element
                ans = max(ans, right[i + 1] + 1);

                // If the two sides can be connected,
                // take both sides + replaced element
                if (nums[i - 1] <= nums[i + 1]) {
                    ans = max(ans,
                             left[i - 1] + 1 + right[i + 1]);
                }
            }
        }

        return ans;
    }
};