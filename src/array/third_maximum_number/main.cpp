/**
 * Source: https://leetcode.com/problems/third-maximum-number/
 * 
 * Given a non-empty array of integers, return the third maximum number in this array.
 * If it does not exist, return the maximum number.
 * The time complexity must be in O(n).
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <vector>
#include <unordered_set>

namespace {

   class Solution {
   public:
      int thirdMax(const std::vector<int>& nums) {
         if (nums.empty())
            return 0;

         std::unordered_set<int> cache;
         int orderedMax[] = {
            std::numeric_limits<int>::min(),
            std::numeric_limits<int>::min(),
            std::numeric_limits<int>::min()
         };

         for (auto n : nums) {
            if (cache.find(n) != cache.end())
               continue;
            cache.insert(n);
            if (n == std::numeric_limits<int>::min())
               continue;
            else if (n > orderedMax[0]) {
               orderedMax[2] = orderedMax[1];
               orderedMax[1] = orderedMax[0];
               orderedMax[0] = n;
            }
            else if (n > orderedMax[1]) {
               orderedMax[2] = orderedMax[1];
               orderedMax[1] = n;
            }
            else if (n > orderedMax[2]) {
               orderedMax[2] = n;
            }
         }
         return orderedMax[cache.size() >= 3 ? 2 : 0];
      }
   };

}

TEST_CASE( "Third Maximum Number", "[test]" ) {
   Solution solver;

   CHECK(0 == solver.thirdMax({}));
   CHECK(1 == solver.thirdMax({ 1 }));
   CHECK(2 == solver.thirdMax({ 1, 2 }));
   CHECK(1 == solver.thirdMax({ 1, 2, 3 }));
   CHECK(2 == solver.thirdMax({ 1, 2, 3, 4 }));
   CHECK(2 == solver.thirdMax({ 1, 3, 4, 2 }));
   CHECK(1 == solver.thirdMax({ 2, 2, 3, 1 }));
   CHECK(std::numeric_limits<int>::min() == solver.thirdMax({ 1, 2, std::numeric_limits<int>::min() }));
   CHECK(
      1 == solver.thirdMax(
         { 
            std::numeric_limits<int>::min(),
            std::numeric_limits<int>::min(),
            std::numeric_limits<int>::min(), 
            std::numeric_limits<int>::min(),
            1, 1, 1
         }
         ));
}
