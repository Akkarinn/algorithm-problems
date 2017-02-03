/**
 * Source: https://leetcode.com/problems/maximum-subarray/
 * 
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 *
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <vector>

namespace {

   class Solution {
   public:
      int maxSubArray(const std::vector<int>& nums) {
         if (nums.empty())
            return 0;

         auto currentSum = nums.front();
         auto maxSum = currentSum;

         auto it = nums.begin() + 1;
         while (it != nums.end()) {
            if (currentSum < 0) {
               // we are coming from a negative sequence
               currentSum = *it;
               maxSum = std::max(*it, maxSum);
            }
            else {
               // we are coming from a positive sequence
               currentSum += *it;
               maxSum = std::max(currentSum, maxSum);
            }
            ++it;
         }
         return maxSum;
      }
   };

}

TEST_CASE( "Maximum Subarray", "[test]" ) {
   Solution solver;

   CHECK(0 == solver.maxSubArray({}));
   CHECK(1 == solver.maxSubArray({ 1 }));
   CHECK(3 == solver.maxSubArray({ -1, 1, 2 }));
   CHECK(6 == solver.maxSubArray({ -2, 1, -3, 4, -1, 2, 1, -5, 4 }));
}
