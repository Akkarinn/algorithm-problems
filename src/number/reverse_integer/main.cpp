/**
 * Source: https://leetcode.com/problems/reverse-integer/
 * 
 * Reverse digits of an integer.
 * 
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>
 
 namespace {
 
   class Solution {
   public:
      int reverse(int x) const {
         long res = 0;
         int value = std::abs(x);
         const int maxThreshold = std::numeric_limits<int>::max() / 10;
         while (value > 0 && res <= maxThreshold)
         {
            // Here we are assured that res*10+lastDigit is at max INTMAX
            res = res * 10 + value % 10;
            value /= 10;
         }
         if (value != 0)
            return 0;
          return x > 0 ? res : - res;
      }
   };

}

TEST_CASE( "Reverse Integer", "[test]" ) {
    Solution solver;

    CHECK( solver.reverse(std::numeric_limits<int>::min()) == 0 );
    CHECK( solver.reverse(std::numeric_limits<int>::max()) == 0 );
    
    CHECK( solver.reverse(-123)       ==  -321 );
    CHECK( solver.reverse(-1)         == -1 );
    CHECK( solver.reverse(0)          ==  0 );
    CHECK( solver.reverse(1)          ==  1 );
    CHECK( solver.reverse(123)        ==  321 );
    CHECK( solver.reverse(1463847412) ==  2147483641 );
}
