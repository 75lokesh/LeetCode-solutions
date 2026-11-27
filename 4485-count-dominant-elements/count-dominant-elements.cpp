class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 1;
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            int sum = 0;
            int div = 0;
            if(i>0){
                sum += nums[i-1];
                div++;
            }
            if(i<n-1){
                sum+=nums[i+1];
                div++;
            }
            if(1.0*nums[i]>= 1.0*sum/div){
                ans++;
            }
        }
        return ans;
    }
};