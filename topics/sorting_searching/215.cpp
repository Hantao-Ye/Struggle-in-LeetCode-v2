#include <algorithm>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

class Solution
{
public:
    int findKthLargest(std::vector<int> &nums, int k)
    {
        quickSelect(nums, k, 0, nums.size() - 1);

        return nums[k - 1];
    }

    void quickSelect(std::vector<int> &nums, int k, int low, int high)
    {
        if (low < 0 || low >= high || high >= nums.size())
        {
            return;
        }

        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(low, high);

        int pivot_idx = dis(gen);
        int pivot = nums[pivot_idx];

        int i = low;
        int left_most = low;
        int right_most = high;

        while (i <= right_most)
        {
            if (nums[i] > pivot)
            {
                std::swap(nums[left_most++], nums[i++]);
            }
            else if (nums[i] < pivot)
            {
                std::swap(nums[right_most--], nums[i]);
            }
            else
            {
                i++;
            }
        }

        if (k < left_most)
        {
            quickSelect(nums, k, low, left_most - 1);
        }
        else if (k > right_most)
        {
            quickSelect(nums, k, right_most + 1, high);
        }
    }

    void quickSort(std::vector<int> &nums, int lo, int hi)
    {
        if (lo < 0 || lo >= hi || hi >= nums.size())
        {
            return;
        }

        int pivot = partition(nums, lo, hi);

        quickSort(nums, lo, pivot - 1);
        quickSort(nums, pivot + 1, hi);
    }

    int partition(std::vector<int> &nums, int lo, int hi)
    {
        int pivot = nums[hi];

        int i = lo;
        for (int j = lo; j < hi; j++)
        {
            if (nums[j] <= pivot)
            {
                std::swap(nums[i], nums[j]);
                i++;
            }
        }

        std::swap(nums[hi], nums[i]);

        return i;
    }

private:
    std::random_device rd;
};

int main()
{
    Solution sol;
    std::string line;

    while (true)
    {
        std::getline(std::cin, line);
        if (line.size() < 1)
        {
            break;
        }

        std::istringstream iss(line);

        int val;
        std::vector<int> input;

        while (iss >> val)
        {
            input.push_back(val);
        }

        std::getline(std::cin, line);
        val = std::stoi(line);

        std::cout << sol.findKthLargest(input, val) << std::endl;
    }

    return 0;
}