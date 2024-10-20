class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int maxPriceAtRight = prices[len-1];
        int maxProfit = 0;

        for (int i = len-1; i >= 0; --i) {
            if (prices[i] > maxPriceAtRight) {
                maxPriceAtRight = prices[i];
            }

            maxProfit = max(maxProfit, maxPriceAtRight - prices[i]);
        }

        return maxProfit;
    }
};
