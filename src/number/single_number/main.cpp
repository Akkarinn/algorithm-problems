/**
 * Source: https://leetcode.com/problems/single-number/
 * 
 * Given an array of integers, every element appears twice except for one. Find that single one.
 * 
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>
 
#include <functional>
#include <numeric>
#include <vector>

 namespace {
 
   class Solution {
   public:
      int singleNumber(std::vector<int>& nums) const {
         return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
      }
   };

}

TEST_CASE( "Single Number", "[test]" ) {
    Solution solver;

    std::vector<int> nums;
    CHECK( solver.singleNumber(nums) == 0 );

    nums.push_back(1);
    CHECK( solver.singleNumber(nums) == 1 );

    nums.push_back(1);
    nums.push_back(2);
    CHECK( solver.singleNumber(nums) == 2 );

    nums.push_back(-1);
    nums.push_back(-1);
    CHECK( solver.singleNumber(nums) == 2 );
}
