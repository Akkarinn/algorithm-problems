/**
 * Source: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 * 
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <vector>

namespace {

   class Solution {
   public:
      std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
         if (nums.size() < 2)
            return std::vector<int>();

         std::vector<int> missing(1 + *std::max_element(nums.begin(), nums.end()), 0);
         std::iota(missing.begin(), missing.end(), 0);
         for (auto num : nums)
            missing[num] = 0;
         missing.erase(std::remove(missing.begin(), missing.end(), 0), missing.end());
         return missing;
      }
   private:
      static bool areSuccessiveNumber(int a, int b) {
         return (a + 1) == b;
      }
   };
}

TEST_CASE( "Disappeared Numbers", "[test]" ) {
   Solution solver;
   {
      std::vector<int> input, expected;
      CHECK(expected == solver.findDisappearedNumbers(input));
   }
   {
      std::vector<int> input{ 1 };
      std::vector<int> expected;
      CHECK(expected == solver.findDisappearedNumbers(input));
   }
   {
      std::vector<int> input{ 1, 2, 3 };
      std::vector<int> expected;
      CHECK(expected == solver.findDisappearedNumbers(input));
   }
   {
      std::vector<int> input{ 1, 3 };
      std::vector<int> expected{ 2 };
      CHECK(expected == solver.findDisappearedNumbers(input));
   }
   {
      std::vector<int> input{ 1, 4, 6, 7 };
      std::vector<int> expected{ 2, 3, 5 };
      CHECK(expected == solver.findDisappearedNumbers(input));
   }
   {
      std::vector<int> input{ 4, 3, 2, 7, 8, 2, 3, 1 };
      std::vector<int> expected{ 5, 6 };
      CHECK(expected == solver.findDisappearedNumbers(input));
   }
}
