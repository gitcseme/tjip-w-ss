// TC: O(N)
// MC: O(N)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> L(n), R(n);
        
        // calculate & store max at left from ith position
        L[0] = 0;
        for (int i = 1; i < n; ++i) 
            L[i] = max(height[i-1], L[i-1]);
        
        // calculate & store max at right from ith position
        R[n-1] = 0;
        for (int i = n-2; i >= 0; --i)
            R[i] = max(height[i+1], R[i+1]);
        
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int water = min(L[i], R[i]) - height[i];
            if (water > 0)
                ans = ans + water;
        }
        
        return ans;
    }
};
