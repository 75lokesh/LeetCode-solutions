class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
       int ans  = 0;
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=i; j<n; j++){
                if(target == nums[j]){
                    cnt++;
                }
                if(1.0*cnt > (1.0*(j-i+1)/2)){
                    ans++;
                }
            }
        }
        return ans;
    }
};