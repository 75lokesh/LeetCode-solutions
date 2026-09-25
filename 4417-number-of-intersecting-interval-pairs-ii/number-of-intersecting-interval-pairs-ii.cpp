class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> starts(n), ends(n);

        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        long long ans = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            // Intervals ending before starts[i] don't intersect it.
            while (j < i && ends[j] < starts[i]) {
                j++;
            }

            // Among the i previous intervals, j don't intersect.
            ans += i - j;
        }

        return ans;
    }
};