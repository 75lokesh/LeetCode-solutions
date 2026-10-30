class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int mn = INT_MAX;
        int ans = 0;
        for(int i=0; i<n; i++){
            int temp = nums[i];
            for(int j=i+1; j<n; j++){
                temp += nums[j];
                for(int k=j+1; k<n; k++){
                 temp += nums[k];
                 if(abs(temp - target)<mn){
                     ans = temp;
                     mn = abs(temp - target);
                 }
                 temp-=nums[k];
                }
                temp -= nums[j];
            }
            temp -= nums[i];
        }
        return ans;
    }
};
