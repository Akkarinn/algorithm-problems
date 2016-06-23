/**
 * Source: https://leetcode.com/problems/power-of-two/
 * 
 * Given an integer, write a function to determine if it i
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>
 
 namespace {
 
   class Solution {
   public:
      bool isPowerOfTwo(int n) const {
         if (n == 1)
            return true;
         if (n < 1 || n & 1)
            return false;
         int flag = 2;
         bool result = false;
         while (flag) {
            auto hasDigit = 0 == (n ^ flag);
            if (result && hasDigit)
               return false;
            result = result || hasDigit;
            flag = flag << 1;
         }
         return result;
      }
   };

}

TEST_CASE( "Power Of Two", "[test]" ) {
    Solution solver;
    
    CHECK_FALSE( solver.isPowerOfTwo(-1) );
    CHECK_FALSE( solver.isPowerOfTwo(0) );
    CHECK      ( solver.isPowerOfTwo(1) );
    CHECK(       solver.isPowerOfTwo(2) );
    CHECK_FALSE( solver.isPowerOfTwo(3) );
    CHECK(       solver.isPowerOfTwo(4));
    CHECK_FALSE( solver.isPowerOfTwo(11) );
    CHECK_FALSE( solver.isPowerOfTwo(17) );
    CHECK(       solver.isPowerOfTwo(64) );
    CHECK_FALSE( solver.isPowerOfTwo(std::numeric_limits<int>::min()) );
    CHECK_FALSE( solver.isPowerOfTwo(std::numeric_limits<int>::max()) );
}
