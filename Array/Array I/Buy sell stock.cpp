// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0], min_idx = 0;
        int max_price = prices[0], max_idx = 0;
        int profit = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < min_price)
            {
                min_price = prices[i];
            }

            else
            {
                profit = max(profit, prices[i] - min_price);
            }
        }

        return profit;
    }    
        
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0], min_idx = 0;
        int max_price = prices[0], max_idx = 0;
        int profit = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < min_price)
            {
                min_price = prices[i];
            }

            else
            {
                profit = max(profit, prices[i] - min_price);
            }
        }

        return profit;
    }    
        
};
