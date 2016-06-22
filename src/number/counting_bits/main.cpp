/**
 * Source: https://leetcode.com/problems/counting-bits/
 * 
 * Given a non negative integer number num. For every numbers i in the range 0 = i = num calculate the number of 1's in their binary representation and return them as an array.
 * 
 * Example:
 * For num = 5 you should return [0,1,1,2,1,2].
 * 
 * Follow up:
 * 
 * It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <algorithm>
#include <numeric>

namespace {

   class Solution {
   public:
      std::vector<int> countBits(int num) const {
         std::vector<int> results;
         if (num == 0) {
            results.push_back(0);
         }
         else {
            results.resize(num+1);
            results[0] = 0;
            results[1] = 1;
         
            auto nextPowTwo = 2;
            for (auto i = 2; i <= num; ++i) {
               if (nextPowTwo == i)
			      nextPowTwo = nextPowTwo << 1;
               results[i] = 1 + results[i - (nextPowTwo >> 1)];
            }
         }
         return results;
      }
   };
}      

TEST_CASE( "Counting Bits", "[test]" ) {
   Solution solver;

   std::vector<int> nums;
   nums.push_back(0);
   CHECK( solver.countBits(0) == nums );

   nums.push_back(1);
   CHECK( solver.countBits(1) == nums );

   nums.push_back(1);
   nums.push_back(2);
   CHECK( solver.countBits(3) == nums );

   nums.push_back(1);
   nums.push_back(2);
   CHECK( solver.countBits(5) == nums );
}
