class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();

        vector<long long> prefix(n + 1, 0);

        // even = +b
        // odd  = -a
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0)
                prefix[i + 1] = prefix[i] + b;
            else
                prefix[i + 1] = prefix[i] - a;
        }

        // Coordinate compression
        vector<long long> values = prefix;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        vector<int> tree(values.size() + 1);

        auto update = [&](int pos) {
            pos++;
            while (pos < tree.size()) {
                tree[pos]++;
                pos += pos & -pos;
            }
        };

        auto get = [&](int pos) {
            int sum = 0;
            pos++;

            while (pos > 0) {
                sum += tree[pos];
                pos -= pos & -pos;
            }

            return sum;
        };

        long long ans = 0;

        update(lower_bound(values.begin(), values.end(), prefix[0])
                   - values.begin());

        for (int i = 1; i <= n; i++) {
            int pos = lower_bound(values.begin(), values.end(), prefix[i])
                          - values.begin();

            // Number of previous prefix sums >= prefix[i]
            int smaller = (pos == 0 ? 0 : get(pos - 1));
            int previous = i;

            ans += previous - smaller;

            update(pos);
        }

        return ans;
    }
};
