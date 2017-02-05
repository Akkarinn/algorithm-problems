/**
 * Source: https://leetcode.com/problems/find-all-anagrams-in-a-string/
 * 
 * Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
 *
 * Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
 *
 * The order of output does not matter.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <string>
#include <vector>
#include <unordered_map>

namespace {

   class Solution {
   public:

      std::vector<int> findAnagrams(const std::string& str, const std::string& ref) const {
         std::vector<int> result;

         std::unordered_map<char, int> refCount;
         for (auto r : ref)
            ++refCount[r];

         auto matchIdx = 0;
         for (auto first = 0; first < str.size();) {
            auto it = refCount.end();
            for (; matchIdx < ref.size(); ++matchIdx) {
               it = refCount.find(str[first + matchIdx]);

               // check if we can consume character
               if (refCount.end() == it || it->second == 0)
                  break;
               --(it->second);
            }

            if (refCount.end() == it) {
               // we leave due to unknown character 
               // -> add back all removed character
               // -> advance from matchIdx indexe
               for (auto i = 0; i < matchIdx; ++i)
                  ++(refCount[str[first + i]]);
               first += 1 + matchIdx;
               matchIdx = 0;
            }
            else {
               if (matchIdx == ref.size())
                  result.push_back(first);

               // we leave due to character already fully consummed
               // -> add back first removed character and advance from 1 indexe
               ++(refCount[str[first]]);
               ++first;
               --matchIdx;
            }
         }
         return result;
       }

   };
}
#define COMA ,
TEST_CASE( "Find All Anagrams in a String", "[test]" ) {
   Solution solver;

   CHECK(std::vector<int>{} == solver.findAnagrams("", ""));
   CHECK(std::vector<int>{ 0 } == solver.findAnagrams("a", "a"));
   CHECK(std::vector<int>{ 0 COMA 1 } == solver.findAnagrams("aa", "a"));
   CHECK(std::vector<int>{ 0 COMA 6 } == solver.findAnagrams("cbaebabacd", "abc"));
   CHECK(std::vector<int>{ 0 COMA 1 COMA 2 } == solver.findAnagrams("abab", "ab"));
   CHECK(std::vector<int>{ 1 } == solver.findAnagrams("baa", "aa"));
   CHECK(std::vector<int>{ 3 COMA 4 COMA 6 } == solver.findAnagrams("abaacbabc", "abc"));
}
