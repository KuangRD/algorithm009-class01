class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int power = 31;
        while (n) {
            res += (n & 1) << power;
            n = n >> 1;
            power--;
        }
        return res;
    }
};