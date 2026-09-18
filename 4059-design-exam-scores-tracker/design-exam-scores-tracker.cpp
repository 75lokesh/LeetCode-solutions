class ExamTracker {
public:
    vector<pair<int, long long>> tracker;

    ExamTracker() {
    }

    void record(int time, int score) {
        long long sum = score;

        if (!tracker.empty()) {
            sum += tracker.back().second;
        }

        tracker.push_back({time, sum});
    }

    int findStart(int startTime) {
        int low = 0;
        int high = tracker.size() - 1;
        int ans = tracker.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (tracker[mid].first >= startTime) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int findEnd(int endTime) {
        int low = 0;
        int high = tracker.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (tracker[mid].first <= endTime) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

    long long totalScore(int startTime, int endTime) {
        int left = findStart(startTime);
        int right = findEnd(endTime);

        if (left > right || left == tracker.size()) {
            return 0;
        }

        long long ans = tracker[right].second;

        if (left > 0) {
            ans -= tracker[left - 1].second;
        }

        return ans;
    }
};