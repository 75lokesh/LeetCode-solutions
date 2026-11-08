// class Solution {
// public:
// static bool comparator(string a, string b){
//     int n = a.size();
//     int m = b.size();
//     int temp = max(n,m);
//     int index = 0;
//     while(index<temp){
//         if(a[index%n]>b[index%m]){
//             return false;
//         }
//         else if(b[index%m]>a[index%n]){
//             return true;
//         }
//         index++;
//     }
//     return return n<m;
// }
//     string largestNumber(vector<int>& nums) {
//         int n = nums.size();
//         vector<string> temp;
//         for (int i = 0; i < n; i++) {
//             temp.push_back(to_string(nums[i]));
//         }
//         sort(temp.begin(), temp.end(), comparator);
//         string res = "";
//         for(int i=n-1; i>=0; i--){
//             res+=temp[i];
//         }
//         return res;
//     }
// };
class Solution {
public:
    static bool comparator(string a, string b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> temp;

        for (int num : nums) {
            temp.push_back(to_string(num));
        }

        sort(temp.begin(), temp.end(), comparator);

        string res = "";

        for (string s : temp) {
            res += s;
        }

        if (res[0] == '0') {
            return "0";
        }

        return res;
    }
};