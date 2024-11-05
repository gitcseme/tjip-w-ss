// TC: O(NlogN)
// MC: O(N)

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a.end < b.end;
        });

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto& interval : intervals) {
            if (pq.empty()) {
                pq.push(interval.end);
                continue;
            }

            if (interval.start >= pq.top()) {
                pq.pop();
            }

            pq.push(interval.end);
        }

        return pq.size();
    }
};
