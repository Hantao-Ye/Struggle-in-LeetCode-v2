#include <cstdint>

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t output = 0;
        int times = 32;
        while (times > 0)
        {
            output *= 2;
            output += n % 2;
            n /= 2;

            times--;
        }

        return output;
    }
};