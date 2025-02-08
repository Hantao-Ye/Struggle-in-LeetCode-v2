#include <vector>
#include <iostream>

int maxProfit(std::vector<int> &prices)
{
    int max_profit {};

    int slow_idx {}, fast_idx {};

    for (; fast_idx < prices.size(); fast_idx++)
    {
        if (prices[fast_idx] > prices[slow_idx])
        {
            max_profit += prices[fast_idx] - prices[slow_idx];
        }
        slow_idx = fast_idx;
    }

    return max_profit;
}

int main()
{
}