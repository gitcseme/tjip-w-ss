mt19937 rng(0); // Seed

class Solution {
private:
    int partition(vector<int>& arr, int L, int R) {
        int pivot = arr[R];
        int leftWall = L;

        for (int i = L; i < R; ++i) {
            if (arr[i] >= pivot) {
                swap(arr[leftWall], arr[i]);
                ++leftWall;
            }
        }

        swap(arr[leftWall], arr[R]);
        return leftWall;
    }

    void partialSort(vector<int>& arr, int k) {
        shuffle(arr.begin(), arr.end(), rng); // To break bad orientation (if sorted)

        int len = arr.size();
        int L = 0, R = len-1;
        int pvtIdx, kthIdx = k-1;
        int threshhold = 2 * log2(len); // For sorted sub array 

        while (L < R && threshhold--) {
            pvtIdx = partition(arr, L, R);

            if (pvtIdx < kthIdx) L = pvtIdx + 1;
            else if (pvtIdx > kthIdx) R = pvtIdx - 1;
            else break;
        }
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        partialSort(nums, k);
        return nums[k-1];
    }
};
