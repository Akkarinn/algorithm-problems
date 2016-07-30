/**
 * Source: https://leetcode.com/problems/missing-number/
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 *
 * For example,
 * Given nums = [0, 1, 3] return 2.
 *
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <numeric>
#include <vector>

namespace {

   class Solution {
   public:
      int missingNumber(const std::vector<int>& nums) {
         int sum = std::accumulate(nums.begin(), nums.end(), 0);
         int sumN = (nums.size() * (nums.size() + 1)) / 2;
        
         return sumN - sum;
      }
   };

}

TEST_CASE( "Missing Number", "[test]" ) {
   Solution solver;
   {
      std::vector<int> input;
      CHECK( solver.missingNumber(input) == 0 );
   }
   {
      std::vector<int> input;
      input.push_back(0);

      CHECK( solver.missingNumber(input) == 1 );
   }
   {
      std::vector<int> input;
      input.push_back(0);
      input.push_back(2);

      CHECK( solver.missingNumber(input) == 1 );
   }
   {
      std::vector<int> input;
      input.push_back(0);
      input.push_back(1);
      input.push_back(2);
      input.push_back(4);

      CHECK( solver.missingNumber(input) == 3 );
   }
}
