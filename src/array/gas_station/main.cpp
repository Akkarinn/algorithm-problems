/**
 * Source: https://leetcode.com/problems/move-zeroes/
 * 
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * 
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 * 
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>
 
#include <vector>

namespace {

   class Solution {
   public:
      // 1- We store in a array the (gas-cost) amount available at each station.
      // 2- We cumulate the amount along the path:
      //    Cumulate amount if:
      //       - current amount is negative
      //       - previous cumulated amount is negative
      // 3- Find the starting index of the right most positive sequence.
      // 4- Several case:
      //   - left amount is negative, we have to check the existence of a path by
      //     verfiying that the left amount + right amount is positive, otherwise there
      //     is no path.
      //   - we are at the starting point (or right to him in case first station has positive amount).
      int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) const {
         if (gas.size() != cost.size() || gas.empty())
            return -1;

         // 1-
         std::vector<int> dp_amount(gas);
         for (auto i = 0; i < dp_amount.size(); ++i)
            dp_amount[i] -= cost[i];

         // 2-
         for (auto i = 1; i < dp_amount.size(); ++i) {
            if (dp_amount[i] < 0 || dp_amount[i-1] >= 0)
               dp_amount[i] += dp_amount[i-1];
         }

         // 3-
		 auto idx = static_cast<int>(dp_amount.size());
         while (idx > 1 && dp_amount[idx-1] >= 0)
            --idx;

         // 4-
         if (dp_amount[idx-1] < 0) {
            if (dp_amount.back() + dp_amount[idx-1] >= 0)
               return idx;
            return -1;
         }
         return idx == 1 ? 0 : idx;
      }
   };
}

TEST_CASE( "Gas Station", "[test]" ) {
   Solution solver;
   {
      std::vector<int> gas, cost;
      CHECK( solver.canCompleteCircuit(gas, cost) == -1 );
   }
   {
      std::vector<int> gas, cost;
      gas.push_back(4);
      CHECK( solver.canCompleteCircuit(gas, cost) == -1 );
   }
   {
      std::vector<int> gas, cost;
      gas.push_back(4);
      //--
      cost.push_back(5);

      CHECK( solver.canCompleteCircuit(gas, cost) == -1 );
   }
   {
      std::vector<int> gas, cost;
      gas.push_back(4);
      gas.push_back(2);
      //--
      cost.push_back(2);
      cost.push_back(3);

      CHECK( solver.canCompleteCircuit(gas, cost) == 0 );
   }
   {
      std::vector<int> gas, cost;
      gas.push_back(1);
      gas.push_back(2);
      //--
      cost.push_back(2);
      cost.push_back(1);

      CHECK( solver.canCompleteCircuit(gas, cost) == 1 );
   }
   {
      std::vector<int> gas, cost;
      gas.push_back(1);
      gas.push_back(2);
      gas.push_back(4);
      gas.push_back(1);
      gas.push_back(1);
      gas.push_back(2);
      gas.push_back(3);
      //--
      cost.push_back(2);
      cost.push_back(3);
      cost.push_back(2);
      cost.push_back(3);
      cost.push_back(5);
      cost.push_back(1);
      cost.push_back(1);

      CHECK( solver.canCompleteCircuit(gas, cost) == -1 );
   }
}
