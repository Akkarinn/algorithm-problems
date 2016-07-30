/**
 * Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * 
 * Given a sorted array, remove the duplicates in place such that each element
 * appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with
 * constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <algorithm>
#include <iterator>
#include <vector>

namespace {

   class Solution {
   public:
      int removeDuplicates(std::vector<int>& nums) {
         return std::distance(nums.begin(), std::unique_copy(nums.begin(), nums.end(), nums.begin()));
      }
   };
}

TEST_CASE( "Remove Duplicate", "[test]" ) {
   Solution solver;
   std::vector<int> input, expected;

   CHECK( solver.removeDuplicates(input) == 0 );
   CHECK( input == expected );

   input.push_back(1);
   input.push_back(2);
   expected.push_back(1);
   expected.push_back(2);
   CHECK( solver.removeDuplicates(input) == 2 );
   CHECK( input == expected );
   
   input.push_back(2);
   input.push_back(3);
   expected.push_back(3);
   CHECK( solver.removeDuplicates(input) == 3 );
   CHECK( std::equal(input.begin(), input.begin() + 3,  expected.begin()) );

   input.push_back(3);
   input.push_back(3);
   input.push_back(4);
   input.push_back(4);
   input.push_back(5);
   expected.push_back(4);
   expected.push_back(5);
   CHECK( solver.removeDuplicates(input) == 5 );
   CHECK( std::equal(input.begin(), input.begin() + 3,  expected.begin()) );
}
