/**
 * Source: https://leetcode.com/problems/contains-duplicate/
 * 
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice in
 * the array, and it should return false if every element is distinct.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <iterator>
#include <set>
#include <vector>

namespace {

   class Solution {
   public:
      bool containsDuplicate(std::vector<int>& nums) {
         std::set<int> values;
         std::copy(nums.begin(), nums.end(), std::inserter(values, values.begin()));
         return values.size() != nums.size();
      }
   };
}

TEST_CASE( "Contains Duplicate", "[test]" ) {
   Solution solver;

   std::vector<int> input;
   CHECK(!  solver.containsDuplicate(input) );
   input.push_back(0);
   CHECK(!  solver.containsDuplicate(input) );
   input.push_back(1);
   input.push_back(2);
   CHECK(!  solver.containsDuplicate(input) );
   input.push_back(2);
   CHECK( solver.containsDuplicate(input) );
   input.push_back(2);
   CHECK( solver.containsDuplicate(input) );
   input.push_back(1);
   CHECK( solver.containsDuplicate(input) );
}
