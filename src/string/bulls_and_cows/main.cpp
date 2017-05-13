/**
 * Source: https://leetcode.com/problems/bulls-and-cows/
 * 
 * You are playing the following Bulls and Cows game with your friend:
 * You write down a number and ask your friend to guess what the number is.
 * Each time your friend makes a guess, you provide a hint that indicates
 * how many digits in said guess match your secret number exactly in both
 * digit and position (called "bulls") and how many digits match the secret
 * number but locate in the wrong position (called "cows").
 * Your friend will use successive guesses and hints to eventually derive the
 * secret number.
 *
 * Write a function to return a hint according to the secret number and
 * friend's guess, use A to indicate the bulls and B to indicate the cows.
 *
 * You may assume that the secret number and your friend's guess only contain
 * digits, and their lengths are always equal.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <sstream>

namespace {

   class Solution {
   public:
      std::string getHint(std::string secret, std::string guess) {
         char occurences[10] = { 0 };
         for (auto c : secret)
            occurences[c - '0']++;
         std::size_t nA = 0;
         std::size_t nB = 0;

         // find number of A
         for (auto i = 0; i < guess.size(); ++i) {
            auto& occ = occurences[guess[i] - '0'];
            if (occ && guess[i] == secret[i]) {
               ++nA;
               occ--;
            }
         }
         // find number of B
         for (auto i = 0; i < guess.size(); ++i) {
            auto& occ = occurences[guess[i] - '0'];
            if (occ && guess[i] != secret[i]) {
               ++nB;
               occ--;
            }
         }
         // Build result
         std::stringstream ss;
         ss << nA << "A" << nB << "B";
         return ss.str();
      }
   };
}

TEST_CASE( "Bulls and Cows", "[test]" ) {
   Solution solver;

   CHECK("1A3B" == solver.getHint("1807", "7810"));
   CHECK("1A1B" == solver.getHint("1123", "0111"));
   CHECK("1A0B" == solver.getHint("11", "12"));
   CHECK("0A0B" == solver.getHint("11", "22"));
   CHECK("0A1B" == solver.getHint("13", "21"));
}
