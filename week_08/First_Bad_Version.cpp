// TC: log(N) where N is number of versions
// MC: O(1)

class Solution {
public:
    int firstBadVersion(int n) {
        int L = 1, R = n, M;

        while (L < R) {
            M = L + (R - L) / 2;
            if (isBadVersion(M)) {
                R = M;
            }
            else {
                L = M + 1;
            }
        }

        return L;
    }
};
