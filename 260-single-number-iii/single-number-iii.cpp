class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // unordered_map<int, int> freq;
        // int n = nums.size();
        // for (int i = 0; i < n; i++) {
        //     freq[nums[i]]++;
        // }
        // vector<int> ans;
        // for (auto it : freq) {
        //     if (it.second == 1) {
        //         ans.push_back(it.first);
        //     }        }
        // return ans;
        int n = nums.size();
        long long temp = nums[0];
        for(int i=1; i<n; i++){
            temp^=nums[i];
        }
        temp &= -temp;
        vector<int>ans = {0,0};
        for(int i=0; i<n; i++){
            if((nums[i]&temp)==0){
                ans[0]^=nums[i];
            }
            else{
                ans[1]^=nums[i];
            }
        }
        return ans;
    }
};