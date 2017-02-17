/**
* Source: https://leetcode.com/problems/search-insert-position/
*
* Given a sorted array and a target value, return the index if the
* target is found. If not, return the index where it would be if it
* were inserted in order.
*
* You may assume no duplicates in the array.
*
* Here are few examples.
* [1,3,5,6], 5 → 2
* [1,3,5,6], 2 → 1
* [1,3,5,6], 7 → 4
* [1,3,5,6], 0 → 0
*/
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <algorithm>
#include <vector>

namespace {

   template<typename ForwardIt, typename T>
   ForwardIt my_lower_bound(ForwardIt first, ForwardIt last, const T& value) {
      ForwardIt pivot = first;
      auto rangeLen = std::distance(first, last);
      while (rangeLen > 0) {
         pivot = first;
         std::advance(pivot, rangeLen / 2);
         if (*pivot < value)
            first = ++pivot;
         else
            last = pivot;
         rangeLen = std::distance(first, last);
      }
      return pivot;
   }

   class Solution {
   public:
      int searchInsert(const std::vector<int>& nums, int target) const {
         return static_cast<int>(std::distance(nums.begin(), my_lower_bound(nums.begin(), nums.end(), target)));
      }
   };

}

TEST_CASE("Search Insert Position", "[test]") {
   Solution solver;
   {
      std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8 };
      CHECK(my_lower_bound(v.begin(), v.end(), 1) == std::lower_bound(v.begin(), v.end(), 1));
      CHECK(my_lower_bound(v.begin(), v.end(), 2) == std::lower_bound(v.begin(), v.end(), 2));
      CHECK(my_lower_bound(v.begin(), v.end(), 9) == std::lower_bound(v.begin(), v.end(), 9));
   }
   CHECK(0 == solver.searchInsert({}, 1));
   CHECK(0 == solver.searchInsert({ 2 }, 1));
   CHECK(1 == solver.searchInsert({ 2 }, 3));
   CHECK(2 == solver.searchInsert({ 1, 3, 5, 6 }, 5));
   CHECK(1 == solver.searchInsert({ 1, 3, 5, 6 }, 2));
   CHECK(4 == solver.searchInsert({ 1, 3, 5, 6 }, 7));
   CHECK(0 == solver.searchInsert({ 1, 3, 5, 6 }, 0));
}
