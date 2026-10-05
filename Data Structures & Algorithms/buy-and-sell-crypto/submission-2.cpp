class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t n=prices.size(); size_t l=0;
        int max_profit =0;
        for(size_t i=1;i<n;i++){
            if(prices[i]<prices[l]){l=i; continue;}
            max_profit = std::max(max_profit, prices[i]-prices[l]);
        }
        return max_profit;
    }
};
