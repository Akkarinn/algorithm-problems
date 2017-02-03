/**
 * Source: https://leetcode.com/problems/intersection-of-two-arrays/
 * 
 * Given two arrays, write a function to compute their intersection.
 * Example:
 *    Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 *
 * Note:
 * - Each element in the result must be unique.
 * - The result can be in any order.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <algorithm>
#include <iterator>
#include <set>
#include <vector>

namespace {

   class Solution {
   public:
      std::vector<int> intersection(const std::vector<int>& nums1, const std::vector<int>& nums2) {
         std::vector<int> intersection;
         std::set<int> snums1(nums1.begin(), nums1.end());
         std::set<int> snums2(nums2.begin(), nums2.end());
         std::set_intersection(snums1.begin(), snums1.end(), snums2.begin(), snums2.end(), std::back_inserter(intersection));
         return intersection;
      }
   };

}
#define COMA ,
TEST_CASE( "Intersection of Two Arrays", "[test]" ) {
   Solution solver;

   CHECK(std::vector<int>{} == solver.intersection({}, {}));
   CHECK(std::vector<int>{} == solver.intersection({}, { 1 }));
   CHECK(std::vector<int>{2 COMA 3} == solver.intersection({ 2, 3, 4 }, { 1, 2, 3 }));
   CHECK(std::vector<int>{2} == solver.intersection({ 1, 2, 2, 1 }, { 2, 2 }));
   CHECK(std::vector<int>{2 COMA 3 COMA 4} == solver.intersection({ 1, 2, 2, 1, 5, 4, 3 }, { 2, 4, 2, 3, 7 }));
}
