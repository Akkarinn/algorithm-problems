/**
 * Source: https://leetcode.com/problems/number-complement/
 * 
 * Given a positive integer, output its complement number. The complement strategy
 * is to flip the bits of its * binary representation.
 *
 * Note:
 * The given integer is guaranteed to fit within the range of a 32-bit signed integer.
 * You could assume no leading zero bit in the integer’s binary representation.
 *
 * Example 1:
 * - Input: 5
 * - Output: 2
 * - Explanation: The binary representation of 5 is 101 (no leading zero bits), and its
 * complement is 010. So * you need to output 2.
 * 
 * Example 2:
 * - Input: 1
 * - Output: 0
 * - Explanation: The binary representation of 1 is 1 (no leading zero bits), and its
 * complement is 0. So you need to output 0.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

namespace {
   class Solution {
   public:
      int findComplement(int num) const {
         if (num == 0)
            return 1;

         int complement = 0xffffffff;
         int flag = 1;
         while (0xffffffff != (complement ^ num)) {
            complement &= ~(num & flag);
            flag = flag << 1;
         }
         while (flag) {
            complement &= ~flag;
            flag = flag << 1;
         } 
         return complement;
      }
   };
}

TEST_CASE( "Number Complement", "[test]" ) {
    Solution solver;

    CHECK(solver.findComplement(0) == 1);
    CHECK(solver.findComplement(1) == 0);
    CHECK(solver.findComplement(5) == 2);
    CHECK(solver.findComplement(97) == 30);
}
