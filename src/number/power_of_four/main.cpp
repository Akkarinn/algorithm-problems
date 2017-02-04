/**
 * Source: https://leetcode.com/problems/power-of-four/
 * 
 * Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
 *
 * Example:
 * Given num = 16, return true. Given num = 5, return false.
 *
 * Follow up: Could you solve it without loops/recursion?
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>
 
 namespace {
 
   class Solution {
   public:
      bool isPowerOfFour(int n) const {
         if (n == 1)
            return true;
         if (n < 1 || n & 1)
            return false;
         bool result = false;
         int flag = 4;
         while (flag) {
            auto hasDigit = 0 == (n ^ flag);
            if (result && hasDigit)
               return false;
            result = result || hasDigit;
            flag = flag << 2;
         }
         return result;
      }
   };

}

TEST_CASE( "Power Of Four", "[test]" ) {
    Solution solver;

    CHECK_FALSE(  solver.isPowerOfFour(-1) );
    CHECK_FALSE(  solver.isPowerOfFour(0) );
    CHECK(        solver.isPowerOfFour(1) );
    CHECK_FALSE(  solver.isPowerOfFour(2) );
    CHECK_FALSE(  solver.isPowerOfFour(3) );
    CHECK(        solver.isPowerOfFour(4) );
    CHECK_FALSE(  solver.isPowerOfFour(5) );
    CHECK_FALSE(  solver.isPowerOfFour(6) );
    CHECK_FALSE(  solver.isPowerOfFour(12) );
    CHECK(        solver.isPowerOfFour(16) );
    CHECK(        solver.isPowerOfFour(64) );
    CHECK_FALSE(  solver.isPowerOfFour(std::numeric_limits<int>::min()) );
    CHECK_FALSE(  solver.isPowerOfFour(std::numeric_limits<int>::max()) );
}
