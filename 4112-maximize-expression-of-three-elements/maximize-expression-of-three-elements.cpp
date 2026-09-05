class Solution {
public:
    static bool comparator(int a, int b){
        return a>b;    }
    int maximizeExpressionOfThree(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),comparator);
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            int sum = nums[i];
            for(int j=i+1; j<n; j++){
                sum+=nums[j];
                for(int k=j+1; k<n; k++){
                    sum-=nums[k];
                    ans = max(sum,ans);
                    sum+=nums[k];
                }
                sum-=nums[j];
            }
            sum-=nums[i];
        }
        return ans;
    }
};