/**
 * Source: https://leetcode.com/problems/find-median-from-data-stream/
 * 
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 *
 * Examples: 
 *    [2,3,4] , the median is 3
 *    
 *    [2,3], the median is (2 + 3) / 2 = 2.5
 * 
 * Design a data structure that supports the following two operations:
 * 
 *    void addNum(int num) - Add a integer number from the data stream to the data structure.
 *    double findMedian() - Return the median of all elements so far.
 *
 * For example:
 * 
 *    add(1)
 *    add(2)
 *    findMedian() -> 1.5
 *    add(3) 
 *    findMedian() -> 2
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <functional>
#include <queue>
#include <vector>

namespace {

   class Solution {
       std::priority_queue<int, std::vector<int>, std::less<int> > maxHeap;
       std::priority_queue<int, std::vector<int>, std::greater<int> > minHeap;

   public:

       // Adds a number into the data structure.
       void addNum(int num) {
           auto size = maxHeap.size() + minHeap.size();
           if (maxHeap.empty()) {
               maxHeap.push(num);
               return;
           } else if (minHeap.empty()) {
               if (num > maxHeap.top()) {
                   minHeap.push(num);
               } else {
                   minHeap.push(maxHeap.top());
                   maxHeap.pop();
                   maxHeap.push(num);
               }
               return;
           }

           if (size & 0x1) {
               if (minHeap.empty() || num > maxHeap.top()) {
                   minHeap.push(num);
               } else {
                   minHeap.push(maxHeap.top());
                   maxHeap.pop();
                   maxHeap.push(num);
               }
           } else {
               if (num < minHeap.top()) {
                   maxHeap.push(num);   
               } else {
                   maxHeap.push(minHeap.top());
                   minHeap.pop();
                   minHeap.push(num);
               }
           }
       }

       // Returns the median of current data stream
       double findMedian() {
           auto size = maxHeap.size() + minHeap.size();
           if (!size)
               throw std::logic_error("Cannot find median: collection is empty");
           if (size & 0x1)
               return maxHeap.top();
           return (maxHeap.top() + minHeap.top()) / 2.0;
       }
   };
}

TEST_CASE( "Find Median From Data Stream", "[test]" ) {
   Solution solver;
   
   solver.addNum(1);
   
   CHECK(solver.findMedian() == 1);

   solver.addNum(2);

   CHECK(solver.findMedian() == 1.5);
   CHECK(solver.findMedian() == 1.5);

   solver.addNum(3);

   CHECK(solver.findMedian() == 2);

   solver.addNum(100);

   CHECK(solver.findMedian() == 2.5);
}
