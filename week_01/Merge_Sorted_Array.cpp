// TC: O(N)
// MC: O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, index = m + n - 1;
        
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[index] = nums1[i--];
            }
            else {
                nums1[index] = nums2[j--];
            }

            --index;
        }

        // check if nums2 has remaining elements
        // no need to check nums1 because if they are, then those are already in sorted position
        while (j >= 0) nums1[index--] = nums2[j--];
    }
};
