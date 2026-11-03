// class Solution {
// public:
// void mult(string num1, int a, vector<int>& ans){
//     int f = num1.size()-1;
//     int carry = 0;
//     while(f>=0){
//             int temp1 = num1[f] - '0';
//             int num = temp1*a + carry;
//             int rem = num % 10;
//             carry = num / 10;
//             ans.push_back(rem);
//             f--;
//         }
//         return;
// }
//     string multiply(string num1, string num2) {
//         int n1 = num1.size();
//         int n2 = num2.size();
//         vector<int> ans;
//        vector<vector<int>> res;
       
//         return str;
//     }
// };

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        vector<int> products(n1 + n2, 0);

        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int d1 = num1[i] - '0';
                int d2 = num2[j] - '0';
                products[i + j + 1] += d1 * d2;
            }
        }

        int carry = 0;
        for (int i = products.size() - 1; i >= 0; i--) {
            int total = products[i] + carry;
            products[i] = total % 10;
            carry = total / 10;
        }

        string result = "";
        for (int digit : products)
            result += to_string(digit);

        int pos = result.find_first_not_of('0');
        return pos == string::npos ? "0" : result.substr(pos);
    }
};