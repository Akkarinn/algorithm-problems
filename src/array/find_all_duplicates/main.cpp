/**
 * Source: https://leetcode.com/problems/find-all-duplicates-in-an-array/?tab=Description
 * 
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 *
 * Find all the elements that appear twice in this array.
 *
 * Could you do it without extra space and in O(n) runtime?
 *
 * Example:
 * Input: [4,3,2,7,8,2,3,1]
 * Output: [2,3]
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <vector>

namespace {

   class Solution {
   public:
      std::vector<int> findDuplicates(const std::vector<int>& nums) const {
         std::vector<int> results(1+nums.size(), 0);
         for (auto n : nums)
            ++results[n];
         auto nextInsertionIdx = 0;
         for (auto i = 0; i < results.size(); ++i) {
            if (results[i] == 2)
               results[nextInsertionIdx++] = i;
         }
         results.resize(nextInsertionIdx);
         return results;
      }
   };

}
#define COMA ,
TEST_CASE( "Find All Duplicates", "[test]" ) {
   Solution solver;

   CHECK(std::vector<int>{} == solver.findDuplicates({}));
   CHECK(std::vector<int>{1} == solver.findDuplicates({ 1, 1 }));
   CHECK(std::vector<int>{1} == solver.findDuplicates({ 2, 1, 1 }));
   CHECK(std::vector<int>{1 COMA 2} == solver.findDuplicates({ 2, 1, 2, 1, 3 }));
   CHECK(std::vector<int>{2 COMA 3} == solver.findDuplicates({ 4, 3, 2, 7, 8, 2, 3, 1 }));
}
