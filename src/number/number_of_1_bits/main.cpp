/**
 * Source: https://leetcode.com/problems/number-of-1-bits/
 * 
 * Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
 * 
 * For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <numeric>
#include <cstdint>

namespace {
    class Solution {
    public:
        int hammingWeight(uint32_t n) const{
            int res = 0;
            while (n > 0)
            {
                res += n % 2;
                n = n >> 1;
            }
            return res;
        }
    };
}

TEST_CASE( "Hamming Weight", "[test]" ) {
    Solution solver;

    CHECK( solver.hammingWeight(0) == 0 );
    CHECK( solver.hammingWeight(2) == 1 );
    CHECK( solver.hammingWeight(11) == 3 );
    CHECK( solver.hammingWeight(std::numeric_limits<uint32_t>::max()) == 32 );
}
