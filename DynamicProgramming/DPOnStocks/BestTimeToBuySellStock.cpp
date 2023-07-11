#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int buy=prices[0];
    int profit=0;
    for(int i=1;i<prices.size();i++){
        profit = max(profit,prices[i]-buy);
        buy = min(buy,prices[i]);
    }
    return profit;
}