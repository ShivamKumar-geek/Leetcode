/*
DP

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
      int max [prices.size()];
        int i,j,maxi=-1;
        for(i=prices.size()-1;i>=0;i--)
        {
            if(prices[i]>maxi)
                maxi=prices[i];
            max[i]=maxi;
        }
        int ans=0;
        for(i=0;i<prices.size()-1;i++)
        {
            if((max[i+1]-prices[i])>ans)
                ans=max[i+1]-prices[i];
        }
        return ans;
    }
};