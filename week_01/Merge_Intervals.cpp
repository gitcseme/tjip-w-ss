class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> result;
        int len = intervals.size();

        for (auto& interval : intervals) {
            if (result.empty() || interval[0] > result.back()[1]) {
                result.push_back(interval);
            }
            else {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }

        return result;
    }
};
