/**
 * Source: https://leetcode.com/problems/fizz-buzz/
 * 
 * Write a program that outputs the string representation of numbers from 1 to n.
 *
 * But for multiples of three it should output “Fizz” instead of the number and
 * for the multiples of five output “Buzz”. For numbers which are multiples of
 * both three and five output “FizzBuzz”.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>
 
#include <string>
#include <vector>

 namespace {
 
   class Solution {
   public:
      std::vector<std::string> fizzBuzz(int n) const {
         std::vector<std::string> list;
         if (n > 0) {
            list.resize(n);
            for (int i = 1; i <= n; ++i) {
               auto fizz = (0 == i % 3);
               auto buzz = (0 == i % 5);
               std::string& v = list[i-1];
               if (fizz)
                  v = "Fizz";
               if (buzz)
                  v += "Buzz";
               if (v.empty())
                  v = std::to_string(i);
            }
         }
         return list;
      }
   };

}
#define COMA ,
TEST_CASE( "Fizz Buzz", "[test]" ) {
    Solution solver;
    
    CHECK(std::vector<std::string>{} == solver.fizzBuzz(-1));
    CHECK(std::vector<std::string>{} == solver.fizzBuzz(0));
    CHECK(std::vector<std::string>{"1"} == solver.fizzBuzz(1));
    CHECK(std::vector<std::string>{"1" COMA "2"} == solver.fizzBuzz(2));
    CHECK(std::vector<std::string>{"1" COMA "2" COMA "Fizz"} == solver.fizzBuzz(3));
    CHECK(std::vector<std::string>{
      "1" COMA "2" COMA "Fizz" COMA "4" COMA
      "Buzz" COMA "Fizz" COMA "7" COMA "8" COMA
      "Fizz" COMA "Buzz" COMA "11" COMA "Fizz" COMA
      "13" COMA "14" COMA "FizzBuzz"} == solver.fizzBuzz(15));
}
