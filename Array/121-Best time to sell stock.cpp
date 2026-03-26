#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int> &prices) {
    int maxProfit, minPrice;

    minPrice = prices[0];
    maxProfit = 0;

    for (int i = 1; i < prices.size(); i++) {
        // Only update them if the current price gives a bigger profit
        // or if it is smaller than the past minimum price
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }

    return maxProfit;
}

int main() {

    vector<int> input = {7, 7, 7, 7, 1};

    cout<<maxProfit(input)<<endl;

    return 0;
}