// class Solution {
// public:
//     int titleToNumber(string columnTitle) {
//         unordered_map<char, int> alphabetMap;

//         // 2. Populate the map dynamically using a loop
//         for (char ch = 'A'; ch <= 'Z'; ++ch) {
//             // 'A' - 'A' + 1 = 0 + 1 = 1
//             // 'B' - 'A' + 1 = 1 + 1 = 2, and so on...
//             alphabetMap[ch] = ch - 'A' + 1;
//         }
//         int n = columnTitle.size();
//         if(n==0){
//             return 0;
//         }
//         int ans = 1;
//         for (int i = 0; i < n - 1; i++) {
//               ans *= alphabetMap[i];
//         }
//         // cout<<ans<<endl;
//         if(ans!=1){
//             ans *= 26;
//         }
//         else{
//             ans=0;
//         }
//         // cout<<ans<<endl;
//         ans += alphabetMap[n-1];
//         return ans;
//     }
// };
class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long ans = 0; // Using long long prevents integer overflow for large test cases
        
        for (char ch : columnTitle) {
            // 1. Shift the existing total to the left by one base-26 place value
            ans = ans * 26;
            
            // 2. Add the value of the current capital letter (A=1, B=2, etc.)
            ans += (ch - 'A' + 1);
        }
        
        return static_cast<int>(ans);
    }
};
