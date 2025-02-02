// TC: log(N) * N where N is the size of dist array
// MC: O(N)

class Solution {
private:
    bool isReachable(vector<int>& dist, double hour, int speed) {
        double elapsed_time = 0.00;
        for (int i = 0; i < dist.size(); ++i) {
            if (i == dist.size() - 1) {
                elapsed_time += (1.00 * dist[i]) / speed;
            }
            else {
                elapsed_time += (dist[i] + speed - 1) / speed; // ceil (a/b) = (a + b - 1) / b 
            }
        }

        return elapsed_time <= hour;
    }

public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int L = 1, R = INT_MAX / 2, M;

        while (L < R) {
            M = L + (R - L) / 2;

            if (isReachable(dist, hour, M)) {
                R = M;
            }
            else {
                L = M + 1;
            }
        }

        return L == INT_MAX / 2 ? -1 : L;
    }
};
