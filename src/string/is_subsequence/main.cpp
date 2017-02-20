/**
 * Source: https://leetcode.com/problems/is-subsequence/?tab=Description
 * 
 * Given a string s and a string t, check if s is subsequence of t.
 *
 * You may assume that there is only lower case English letters in both
 * s and t. t is potentially a very long (length ~= 500,000) string, and
 * s is a short string (<=100).
 *
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ace" is a subsequence
 * of "abcde" while "aec" is not).
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <string>

namespace {

   class Solution {
   public:

      bool isSubsequence(const std::string& pattern, const std::string& text) const {
         auto patternIt = pattern.begin();
         auto it = text.begin();
         while (patternIt != pattern.end()) {
            while (it != text.end() && *it != *patternIt)
               ++it;
            if (it == text.end())
               break;
            ++patternIt;
            ++it;
         }
         return patternIt == pattern.end();
       }

   };
}

TEST_CASE( "Is Subsequence", "[test]" ) {
   Solution solver;

   CHECK(solver.isSubsequence("", ""));
   CHECK(solver.isSubsequence("", "a"));
   CHECK(solver.isSubsequence("a", "a"));
   CHECK(solver.isSubsequence("a", "ab"));
   CHECK(solver.isSubsequence("aa", "aab"));
   CHECK(solver.isSubsequence("ace", "abcde"));
   CHECK_FALSE(solver.isSubsequence("aec", "abcde"));
   CHECK_FALSE(solver.isSubsequence("a", ""));
}
