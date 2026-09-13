class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int index = 1;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(k*index==nums[i]){
                index++;
            }
        }
        return k*index;
    }
};