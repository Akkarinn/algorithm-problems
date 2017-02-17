/**
 * Source: https://leetcode.com/problems/queue-reconstruction-by-height/
 * 
 * Suppose you have a random list of people standing in a queue.
 * Each person is described by a pair of integers (h, k), where h is the height
 * of the person and k is the number of people in front of this person who have
 * a height greater than or equal to h. Write an algorithm to reconstruct the queue.
 *
 * Note: The number of people is less than 1,100.
 *
 * Example:
 * - Input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 * - Output: [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>
 
#include <algorithm>
#include <list>
#include <vector>

 namespace {
 
   class Solution {
   public:
      std::vector<std::pair<int, int>> reconstructQueue(std::vector<std::pair<int, int>> people) const {
         typedef std::pair<int, int> Person;
         typedef std::list<Person> Queue;

         // Sort by decrease size and then increasing position
         std::sort(people.begin(), people.end(),
            [](const Person& a, const Person& b) {
               if (a.first == b.first)
                  return a.second < b.second;
               return a.first > b.first;
            });

         // Create the queue, starting by the person with highest size, its position is given directly
         Queue workingQueue;
         for (auto p : people) {
            auto insertIt = workingQueue.begin();
            std::advance(insertIt, p.second);
            workingQueue.insert(insertIt, p);
         }
         return {workingQueue.begin(), workingQueue.end()};
      }
   };

}

TEST_CASE( "Queue Reconstruction by Height", "[test]" ) {
    Solution solver;
    std::vector<std::pair<int, int> > input{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    std::vector<std::pair<int, int> > target{{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}};
    CHECK(target == solver.reconstructQueue(input));
}
