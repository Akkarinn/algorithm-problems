/**
 * Source: https://leetcode.com/problems/product-of-array-except-self/
 * 
 * Given an array of n integers where n > 1, nums, return an array output
 * such that output[i] is equal to the product of all the elements of nums
 * except nums[i].
 *
 * Solve it without division and in O(n).
 *
 * For example, given [1,2,3,4], return [24,12,8,6].
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <iterator>
#include <set>
#include <vector>

namespace {

   class Solution {
   public:
      std::vector<int> productExceptSelf(const std::vector<int>& nums) {
         if (nums.empty()) {
            return std::vector<int>();
         }
         std::vector<int> res(nums.size(), 1);
         std::vector<int> tmp(nums.size(), 1);
         for (auto i = 1u; i < nums.size(); ++i) {
            res[i] = res[i-1] * nums[i-1];
         }
         for (auto i = nums.size() - 1; i > 0; --i) {
            tmp[i-1] = tmp[i] * nums[i];
         }
         for (auto i = 0u; i < nums.size(); ++i) {
            res[i] *= tmp[i];
         }
         return res;
      }
   };
}

TEST_CASE( "Product Except Self", "[test]" ) {
   Solution solver;
   {
      std::vector<int> input, expected;
      CHECK( solver.productExceptSelf(input) == expected );
   }
   {
      std::vector<int> input, expected;
       input.push_back(1);
      expected.push_back(1);
      CHECK( solver.productExceptSelf(input) == expected );
   }
   {
      std::vector<int> input, expected;
      input.push_back(2);
      expected.push_back(1);
      CHECK( solver.productExceptSelf(input) == expected );
   }
   {
      std::vector<int> input, expected;
      input.push_back(-1);
      input.push_back(2);
      expected.push_back(2);
      expected.push_back(-1);
      CHECK( solver.productExceptSelf(input) == expected );
   }
   {
      std::vector<int> input, expected;
      input.push_back(1);
      input.push_back(2);
      input.push_back(3);
      input.push_back(4);
      expected.push_back(24);
      expected.push_back(12);
      expected.push_back(8);
      expected.push_back(6);
      CHECK( solver.productExceptSelf(input) == expected );
   }
}
