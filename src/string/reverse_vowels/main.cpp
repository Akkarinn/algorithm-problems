/**
 * Source: https://leetcode.com/problems/reverse-vowels-of-a-string/
 * 
 * Write a function that takes a string as input and reverse only the vowels of a string.
 *
 * Example 1:
 * - Given s = "hello", return "holle".
 *
 * Example 2:
 * - Given s = "leetcode", return "leotcede".
 *
 * Note:
 * The vowels does not include the letter "y".
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <cctype>
#include <string>

namespace {

   class Solution {
   public:

      std::string reverseVowels(const std::string& s) {
         auto result = s;

         if (s.empty())
            return s;

         auto first = 0;
         auto last = s.size() - 1;
         while (first < last) {
            while (first < last && !isVowel(s[first]))
               ++first;
            while (first < last && !isVowel(s[last]))
               --last;
            if (first < last) {
               std::swap(result[first], result[last]);
            }
            ++first;
            last = last == 0 ? 0 : last - 1; // protect underflow
         }
         return result;
      }

   private:
      static bool isVowel(char c) {
         switch (tolower(c)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
               return true;
            default:
               return false;
         }
      }
   };

}

TEST_CASE( "Reverse Vowels", "[test]" ) {
   Solution solver;

   CHECK("" == solver.reverseVowels(""));
   CHECK("ezart" == solver.reverseVowels("azert"));
   CHECK("ezarty" == solver.reverseVowels("azerty"));
   CHECK("a." == solver.reverseVowels("a."));
   CHECK("aA" == solver.reverseVowels("Aa"));
}
