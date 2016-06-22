/**
 * Source: https://leetcode.com/problems/add-digits/
 * 
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 * 
 * For example:
 * 
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 * 
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>
 
 namespace {
 
   class Solution {
   public:
      int addDigits(int num) const {
         if (num < 10)
            return num;
         return addDigits(addDigits(num / 10) + addDigits(num % 10));
      }
   };

}

TEST_CASE( "Add Digits", "[test]" ) {
    Solution solver;
    
    CHECK( solver.addDigits(-1)        == -1 );
    CHECK( solver.addDigits(0)         ==  0 );
    CHECK( solver.addDigits(1)         ==  1 );
    CHECK( solver.addDigits(38)        ==  2 );
    CHECK( solver.addDigits(158465465) ==  8 );
}
