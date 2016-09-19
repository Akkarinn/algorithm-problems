/**
 * Source: https://leetcode.com/problems/move-zeroes/
 * 
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * 
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 * 
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>
 
#include <vector>

namespace {

   class Solution {
   public:
      typedef std::vector<int>::iterator IT;

      void moveZeroes(std::vector<int>& nums) const {
         moveZeroes(nums.begin(), nums.end());
      }

      void moveZeroes(IT start, IT end) const {
         while (start != end)
         {
            IT zero = std::find(start, end, 0);
            if (zero == end)
               return;
            start = zero+1;
            while (start != end && *start == 0)
               ++start;
            if (start == end)
               return;
            std::swap(*zero, *start);
            start = zero+1;
         }
      }
   };
}

TEST_CASE( "Move Zeroes", "[test]" ) {
   Solution solver;
   {
      std::vector<int> test, ref;
      solver.moveZeroes(test);
      CHECK( test == ref );
   }
   {
      std::vector<int> test, ref;
      test.push_back(0);
      ref.push_back(0);
      solver.moveZeroes(test);
      CHECK( test == ref );
   }
   {
      std::vector<int> test, ref;
      test.push_back(1);
      test.push_back(0);
      ref.push_back(1);
      ref.push_back(0);
      solver.moveZeroes(test);
      CHECK( test == ref );
   }
   {
      std::vector<int> test, ref;
      test.push_back(1);
      ref.push_back(1);
      solver.moveZeroes(test);
      CHECK( test == ref );
   }
   {
      std::vector<int> test, ref;
      test.push_back(1);
      test.push_back(0);
      test.push_back(2);
      test.push_back(0);
      ref.push_back(1);
      ref.push_back(2);
      ref.push_back(0);
      ref.push_back(0);
      solver.moveZeroes(test);
      CHECK( test == ref );
   }
}
