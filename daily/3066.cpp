#include <iostream>
#include <queue>
#include <vector>

class Solution
{
public:
    int minOperations(std::vector<int> &nums, int k)
    {
        int count = 0;

        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;

        for (const int &num : nums)
        {
            pq.push(num);
        }

        while (pq.top() < k && pq.size() >= 2)
        {
            long long first = pq.top();
            pq.pop();

            long long second = pq.top();
            pq.pop();

            pq.push(std::min(first, second) * 2 + std::max(first, second));
            count++;
        }

        return count;
    }
};

int main()
{
    Solution sol;

    std::vector<int> nums = {2, 11, 10, 1, 3};
    int k = 10;

    std::cout << sol.minOperations(nums, k) << std::endl;
}