class Solution {
public:
    long long countDistinct(long long n) {
        long long ans = 0;
        long long temp = n;
        int cnt = 0;
        vector<int> nums;
        while (temp > 0) {
            int rem = temp % 10;
            nums.push_back(rem);
            cnt++;
            temp /= 10;
        }
        if (cnt != 1) {
            for (int i = 1; i <= cnt - 1; i++) {
                ans += (1LL * pow(9, i));
            }
        }

        int m = nums.size();
        // for (int i = 0; i < m - 1; i++) {
        //     if (nums[i] != 0) {
        //         continue;
        //     } else if ((nums[i] == 0) && (nums[i + 1] > 1)) {
        //         nums[i] = 9;
        //         nums[i + 1]--;
        //     } else if ((nums[i] == 0) && (nums[i + 1] <= 1)) {
        //         nums[i + 1] = 0;
        //         break;
        //     }
        // }

       int cnt0 = 0;
            for (int i = m-1; i >=0 ; i--) {
                if(nums[i]==0){
                    cnt0++;
                    break;
                }
                if (nums[i] > 1) {
                    ans += 1LL * (nums[i] - 1) * pow(9, i);
                }
            }
        if(cnt0==0){
            ans++;
        }
        
        // ans += 1LL * ans2;
        return ans;
    }
};