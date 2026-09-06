class Solution {
public:
    static bool comparator(vector<int>&a, vector<int>&b){
        return a[0]>b[0];
    }
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if(n<=2){
            return -1;
        }
       vector<vector<int>> nums2(n); 
        for(int i=0; i<n; i++){
            nums2[i] = {nums[i],i};
        }
        sort(nums2.begin(),nums2.end());
        int ans = INT_MAX;
        for(int i=2; i<n; i++){
            if((nums2[i-2][0]== nums2[i-1][0])&&(nums2[i-1][0]==nums2[i][0])){
                ans = min(ans, abs(nums2[i-2][1]-nums2[i-1][1]) + abs(nums2[i-1][1]-nums2[i][1]) + abs(nums2[i][1]-nums2[i-2][1]));
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};