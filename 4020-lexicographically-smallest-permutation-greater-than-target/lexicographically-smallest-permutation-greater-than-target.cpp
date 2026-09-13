// class Solution {
// public:
//     string lexGreaterPermutation(string s, string target) {
//         unordered_map<char, int> map;
//         int n = s.size();
//         for (int i = 0; i < n; i++) {
//             map[s[i]]++;
//         }
//         string str = "";
//         // for(char j = target[0]; j<='z'; j++){
//         //         if((map.find(j)!=map.end()) && (map[j]!=0)){
//         //             str += j;
//         //             map[j]--;
//         //             mark = 1;
//         //             break;
//         //         }
//         //         if(!mark){
//         //             return "";
//         //         }
//         //     }
//         int index = -1;
//         for (int i = 0; i < n; i++) {
//             if ((map.find(target[i]) != map.end()) && (map[target[i]] != 0)) {
//                 str += target[i];
//                 map[target[i]]--;
//             } else {
//                 bool mark = 0;
//                 for (char j = target[i] + 1; j <= 'z'; j++) {
//                     if ((map.find(j) != map.end()) && (map[j] != 0)) {
//                         str += j;
//                         map[j]--;
//                         mark = 1;
//                         index = i;
//                         break;
//                     }
//                 }
//                 if (!mark) {
//                     return "1";
//                 }
//                 break;
//             }
//         }
//         cout<<str<<endl;
//         if(index!=-1){
//         for (int i = index + 1; i < n; i++) {
//             bool mark = 0;
//             for (char j = 'a'; j <= 'z'; j++) {
//                 if ((map.find(j) != map.end()) && (map[j] != 0)) {
//                     str += j;
//                     map[j]--;
//                     mark = 1;
//                     index = i;
//                     break;
//                 }
//             }
//             if (!mark) {
//                 return "2";
//             }
//         }}
//         if (str == target) {
//             for (int i = n - 1; i >= 0; i--) {

//                 // restore the character at position i
//                 map[target[i]]++;

//                 // find a character greater than target[i]
//                 for (char j = target[i] + 1; j <= 'z'; j++) {

//                     if (map[j] > 0) {
//                         string ans = target.substr(0, i);
//                         ans += j;
//                         map[j]--;

//                         // fill remaining characters in ascending order
//                         for (char k = 'a'; k <= 'z'; k++) {
//                             while (map[k] > 0) {
//                                 ans += k;
//                                 map[k]--;
//                             }
//                         }

//                         return ans;
//                     }
//                 }
//             }

//             return "3";
//         }
//         return str;
//     }
// };
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        int n = s.size();

        unordered_map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        string str = "";

        // Match target as much as possible
        int i = 0;

        while (i < n && mp[target[i]] > 0) {
            str += target[i];
            mp[target[i]]--;
            i++;
        }

        // Now try to make the answer greater.
        // Start from the position where we stopped
        // and then backtrack.
        for (int pos = i; pos >= 0; pos--) {

            // If pos is a previously matched position,
            // restore that character.
            if (pos < i) {
                mp[target[pos]]++;
            }

            // Try the smallest character greater than target[pos]
            if (pos < n) {

                for (char c = target[pos] + 1; c <= 'z'; c++) {

                    if (mp[c] > 0) {

                        string ans = target.substr(0, pos);

                        ans += c;
                        mp[c]--;

                        // Fill the remaining characters
                        // in ascending order.
                        for (char x = 'a'; x <= 'z'; x++) {
                            while (mp[x] > 0) {
                                ans += x;
                                mp[x]--;
                            }
                        }

                        return ans;
                    }
                }
            }
        }

        return "";
    }
};