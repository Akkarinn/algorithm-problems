/**
 * Source: https://leetcode.com/problems/nim-game/
 * 
 * You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.
 * 
 * Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.
 * 
 * For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

namespace {
   class Solution {
   public:
      bool canWinNim(int n) const {
          return n % 4 != 0;
      }
   };
}

TEST_CASE( "Nim Game", "[test]" ) {
    Solution solver;

    CHECK( solver.canWinNim(-40) == false );
    CHECK( solver.canWinNim(-1) == true );
    CHECK( solver.canWinNim(0) == false );
    CHECK( solver.canWinNim(1) == true );
    CHECK( solver.canWinNim(4) == false );
    CHECK( solver.canWinNim(40) == false );
    CHECK( solver.canWinNim(111) == true );
}
