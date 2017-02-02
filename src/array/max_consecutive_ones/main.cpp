/**
 * Source: https://leetcode.com/problems/max-consecutive-ones/
 * 
 * Given a binary array, find the maximum number of consecutive 1s in this array.
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive 1s.
 *              The maximum number of consecutive 1s is 3.
 * Note:
 * - The input array will only contain 0 and 1.
 * - The length of input array is a positive integer and will not exceed 10,000
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <iterator>
#include <set>
#include <vector>

namespace {
   class Solution {
   public:
      int findMaxConsecutiveOnes(const std::vector<int>& nums) const {
         int maxDistance = 0;

         auto first = nums.begin();
         auto last = nums.end();

         while (first != last) {
            auto it = std::find(first, last, 0);
            auto curDistance = static_cast<int>(std::distance(first, it));
            maxDistance = std::max(curDistance, maxDistance);
            first = std::find(it, last, 1);
         }
         return maxDistance;
      }
   };
}

TEST_CASE( "Max Consecutive Ones", "[test]" ) {
   Solution solver;

   CHECK(0 == solver.findMaxConsecutiveOnes({}));
   CHECK(0 == solver.findMaxConsecutiveOnes({0}));
   CHECK(1 == solver.findMaxConsecutiveOnes({1}));
   CHECK(2 == solver.findMaxConsecutiveOnes({1, 0, 1, 1, 0, 1, 0}));
   CHECK(3 == solver.findMaxConsecutiveOnes({1, 0, 1, 1, 0, 1, 0, 1, 1, 1}));
   CHECK(4 == solver.findMaxConsecutiveOnes({1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1}));
}
