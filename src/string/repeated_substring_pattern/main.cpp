/**
 * Source: https://leetcode.com/problems/repeated-substring-pattern/
 * 
 * Given a non-empty string check if it can be constructed by taking a
 * substring of it and appending multiple copies of the substring together.
 * You may assume the given string consists of lowercase English letters
 * only and its length will not exceed 10000.
 *
 * Example 1:
 * - Input: "abab"
 * - Output: True
 *
 * Explanation: It's the substring "ab" twice.
 *
 * Example 2:
 * - Input: "aba"
 * - Output: False
 * 
 * Example 3:
 * - Input: "abcabcabcabc"
 * - Output: True
 * Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <algorithm>
#include <functional>
#include <string>

namespace {

   class Solution {
   public:

       bool repeatedSubstringPattern(const std::string& str) const {
         if (str.size() < 2)
            return false;
         if (0 == str.size() % 2) {
            auto pivot = str.begin() + str.size() / 2;
            if (std::equal(str.begin(), pivot, pivot))
               return true;
         }
         if (0 == str.size() % 3) {
            auto rangeLen = str.size() / 3;
            auto pivotLeft = str.begin() + rangeLen;
            auto pivotRight = pivotLeft + rangeLen;
            if (std::equal(str.begin(), pivotLeft, pivotLeft) && std::equal(pivotLeft, pivotRight, pivotRight))
                return true;
         }
         return str.end() == std::find_if(str.begin(), str.end(), [&](char c) { return c != *str.begin(); });
       }

   };
}

TEST_CASE( "Repeated Substring Pattern", "[test]" ) {
   Solution solver;

   CHECK_FALSE(solver.repeatedSubstringPattern(""));
   CHECK(solver.repeatedSubstringPattern("abab"));
   CHECK(solver.repeatedSubstringPattern("ababab"));
   CHECK(solver.repeatedSubstringPattern("abcabcabcabc"));
   CHECK(solver.repeatedSubstringPattern("aaaaaaaaaaaaa"));
   CHECK_FALSE(solver.repeatedSubstringPattern("aabcaaabcaaabcaabca")); // Ref is False -> no ambiguity //allowed
   CHECK_FALSE(solver.repeatedSubstringPattern("a"));
   CHECK_FALSE(solver.repeatedSubstringPattern("ab"));
   CHECK_FALSE(solver.repeatedSubstringPattern("aba"));
   CHECK_FALSE(solver.repeatedSubstringPattern("abac"));
   CHECK_FALSE(solver.repeatedSubstringPattern("aabaaba"));
   CHECK_FALSE(solver.repeatedSubstringPattern("abaabaa"));
}
