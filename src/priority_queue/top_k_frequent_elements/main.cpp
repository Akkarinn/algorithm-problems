/**
 * Source: https://leetcode.com/problems/top-k-frequent-elements/
 * 
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <queue>
#include <unordered_map>
#include <vector>

namespace {

   class Solution {
      typedef int T_Frequence;
      typedef int T_Value;
      typedef std::pair<T_Frequence, T_Value> T_Element;

      struct ElementGreater {
         bool operator()(const T_Element& a, const T_Element& b) const {
            return a.first > b.first;
         }
      };

   public:

      std::vector<int> topKFrequent(const std::vector<int>& nums, int k) const {
         if (k == 0)
            return {};

         std::unordered_map<int, int> frequences;
         for (auto n : nums)
            ++frequences[n];

         std::priority_queue<T_Element, std::vector<T_Element>, ElementGreater> kMostFreq;
         for (auto freq : frequences) {
            if (k > 0 || kMostFreq.top().first < freq.second) {
               if (! kMostFreq.empty() && k == 0)
                  kMostFreq.pop();
               kMostFreq.push(T_Element(freq.second, freq.first));
               k = std::max(0, k-1);
            }
         }
         std::vector<int> res;
         while (kMostFreq.size()) {
            res.push_back(kMostFreq.top().second);
            kMostFreq.pop();
         }
         std::sort(res.begin(), res.end());
         return res;
      }
   };
}

#define COMA ,
TEST_CASE( "Top k Frequent Elements", "[test]" ) {
   Solution solver;
   
   CHECK(std::vector<int>{} == solver.topKFrequent({}, 0));
   CHECK(std::vector<int>{} == solver.topKFrequent({}, 1));
   CHECK(std::vector<int>{1} == solver.topKFrequent({ 1 }, 1));
   CHECK(std::vector<int>{1 COMA 2} == solver.topKFrequent({ 1, 1, 1, 2, 2, 3 }, 2));
   CHECK(std::vector<int>{1 COMA 2} == solver.topKFrequent({1, 1, 2, 2, 3}, 2));
}
