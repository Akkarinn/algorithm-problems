/**
 * Source: https://leetcode.com/problems/longest-consecutive-sequence
 * 
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 *
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 *
 * Your algorithm should run in O(n) complexity.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>
 
#include <vector>
#include <unordered_set>

namespace {

   class Solution {
   public:
      int longestConsecutive(const std::vector<int>& nums) const {
         if (nums.size() < 2)
            return static_cast<int>(nums.size());

         auto longuestSequence = 0;
         std::unordered_set<int> pendingNums(nums.begin(), nums.end());
         std::unordered_set<int> visitedNums;
         while (!pendingNums.empty()) {
            auto it = pendingNums.begin();
            if (visitedNums.end() == visitedNums.find(*it)) {
               longuestSequence = std::max(longuestSequence,
                  1 + iterate(*it, pendingNums, visitedNums, [](int v) { return ++v; })
                    + iterate(*it, pendingNums, visitedNums, [](int v) { return --v; }));
               visitedNums.insert(*it);
            }
            pendingNums.erase(it);
         }
         return longuestSequence;
      }
   private:
      int iterate(int start, std::unordered_set<int>& pendingNums, std::unordered_set<int>& visitedNums, int(*next)(int)) const {
         auto value = next(start);
         auto itValue = pendingNums.find(value);
         if (pendingNums.end() != itValue) {
            if (visitedNums.end() == visitedNums.find(value)) {
               visitedNums.insert(value);
               pendingNums.erase(itValue);
               return 1 + iterate(value, pendingNums, visitedNums, next);
            }
         }
         return 0;
      }
   };

}

TEST_CASE( "Longest Consecutive Sequence", "[test]" ) {
   Solution solver;
   {
      std::vector<int> test{};
      CHECK(0 == solver.longestConsecutive(test));
   }
   {
      std::vector<int> test{ 1 };
      CHECK(1 == solver.longestConsecutive(test));
   }
   {
      std::vector<int> test{ 1, 2, 3, 5 };
      CHECK(3 == solver.longestConsecutive(test));
   }
   {
      std::vector<int> test{ 3, 2, 1, 5 };
      CHECK(3 == solver.longestConsecutive(test));
   }
   {
      std::vector<int> test{ 100, 4, 200, 1, 3, 2 };
      CHECK(4 == solver.longestConsecutive(test));
   }
   {
      std::vector<int> test{ 9, 10, 100, 4, 200, 1, 3, 2 , 8, 6, 7, 7, 7, 11, 7, 12, 13};
      CHECK(8 == solver.longestConsecutive(test));
   }
}
