/**
 * Source: https://leetcode.com/problems/longest-palindrome/
 * 
 * Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
 *
 * This is case sensitive, for example "Aa" is not considered a palindrome here.
 *
 * Note:
 * Assume the length of given string will not exceed 1,010.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <string>

namespace {

   class Solution {
   public:

       int longestPalindrome(const std::string& str) {
         int nbOccurence[256] = { 0 };
         for (auto c : str)
            ++nbOccurence[c];
         auto lenght = 0;
         bool hasAtLeastOneRest = false;
         for (auto i = 0; i < 256; ++i) {
            lenght += 2 * (nbOccurence[i] / 2);
            hasAtLeastOneRest = hasAtLeastOneRest || (1 == nbOccurence[i] % 2);
         }
         return lenght + (hasAtLeastOneRest ? 1 : 0);
       }

   };
}

TEST_CASE( "Longuest palindrome", "[test]" ) {
   Solution solver;

   CHECK(0 == solver.longestPalindrome(""));
   CHECK(1 == solver.longestPalindrome("a"));
   CHECK(2 == solver.longestPalindrome("aa"));
   CHECK(1 == solver.longestPalindrome("aA"));
   CHECK(7 == solver.longestPalindrome("abccccdd"));
}
