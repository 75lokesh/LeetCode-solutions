// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int, int> freq;
//         for (int it : nums) {
//             freq[it]++;
//         }
//         for (auto it : freq) {
//             if (it.second != 3) {
//                 return it.first;
//             }
//         }
//         return 0;
//     }
// };
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;

        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }

        return ones;
    }
};