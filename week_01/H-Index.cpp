// TC: O(NlogN)
// MC: O(1)

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        
        int mxHIdx = 0, len = citations.size();
        int mxTillNow;

        for (int i = 0; i < len; ++i) {
            mxTillNow = min(citations[i], len - i);
            mxHIdx = max(mxHIdx, mxTillNow);
        }

        return mxHIdx;
    }
};
