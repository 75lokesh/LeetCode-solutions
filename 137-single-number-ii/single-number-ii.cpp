class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int it : nums){
            freq[it]++;
        }
        for(auto it : freq){
            if(it.second != 3){
                return it.first;
            }
        }
        return 0;
    }
};