/**
 * Source: https://leetcode.com/problems/valid-anagram/
 * 
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 *
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <algorithm>
#include <string>

namespace {

   class Solution {
   public:

       bool isAnagram(const std::string& str, const std::string& ref) {
          int strFreq[256] = { 0 };
          int refFreq[ 256 ] = { 0 };
          for (auto c : str)
             ++strFreq[c];
          for (auto c : ref)
             ++refFreq[c];
         return std::equal(
            std::begin(strFreq), std::end(strFreq),
            std::begin(refFreq), std::end(refFreq));
       }

   };
}

TEST_CASE( "Valid Anagram", "[test]" ) {
   Solution solver;

   CHECK(solver.isAnagram("", ""));
   CHECK(solver.isAnagram("a", "a"));
   CHECK(solver.isAnagram("aa", "aa"));
   CHECK(solver.isAnagram("abBa", "Baab"));
   CHECK_FALSE(solver.isAnagram("aa", "aA"));
   CHECK_FALSE(solver.isAnagram("aa", "aaa"));
}
