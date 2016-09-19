/**
 * Source: https://leetcode.com/problems/sort-colors/
 *
 * Given an array with n objects colored red, white or blue, sort them so that objects
 * of the same color are adjacent, with the colors in the order red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue
 * respectively.
 * 
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <algorithm>
#include <vector>

namespace {

   class Solution {
   public:
      void sortColors(std::vector<int>& nums) {
         int nb[] = { 0, 0, 0 };
         for (auto it = nums.begin(); it != nums.end(); ++it) {
            if (*it < 0 || *it > 2)
                  return; // error
            ++nb[*it];
         }
         std::fill(nums.begin(), nums.begin() + nb[0], 0);
         std::fill(nums.begin() + nb[0], nums.begin() + nb[0] + nb[1], 1);
         std::fill(nums.begin() + nb[0] + nb[1], nums.begin() + nb[0] + nb[1] + nb[2], 2);
      }
   };

}

TEST_CASE( "Sort Colors", "[test]" ) {
   Solution solver;
   {
      std::vector<int> input;
      solver.sortColors(input);
      
      CHECK( input.empty() );
   }
   {
      std::vector<int> input;
      input.push_back(0);
      input.push_back(1);
      input.push_back(2);

      solver.sortColors(input);
      
      CHECK( input.size() == 3 );
      CHECK( input[0] == 0 );
      CHECK( input[1] == 1 );
      CHECK( input[2] == 2 );

      input.push_back(2);
      input.push_back(2);
      input.push_back(1);
      input.push_back(2);
      input.push_back(2);
      input.push_back(0);

      solver.sortColors(input);

      CHECK( input.size() == 9 );
      CHECK( input[0] == 0 );
      CHECK( input[1] == 0 );
      CHECK( input[2] == 1 );
      CHECK( input[3] == 1 );
      CHECK( input[4] == 2 );
      CHECK( input[5] == 2 );
      CHECK( input[6] == 2 );
      CHECK( input[6] == 2 );
      CHECK( input[6] == 2 );
   }
}
