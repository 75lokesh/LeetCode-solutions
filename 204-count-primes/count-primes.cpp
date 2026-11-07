// class Solution {
// public:
//     bool PrimeNumber(int num) {
//         if (num == 1) {
//             return false;
//         }
//         for (int i = 2; i * i <= num; i++) {
//             if (num % i == 0) {
//                 return false;
//             }
//         }
//         return true;
//     }
//     int countPrimes(int n) {
//         int cnt = 0;
//         for (int i = 1; i < n; i++) {
//             if (PrimeNumber(i)) {
//                 cnt++;
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }

        int cnt = 0;

        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                cnt++;
            }
        }

        return cnt;
    }
};