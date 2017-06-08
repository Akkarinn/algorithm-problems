/**
 * Source: https://leetcode.com/problems/frog-jump/
 * 
 * A frog is crossing a river. The river is divided into x units and at
 * each unit there may or may not exist a stone. The frog can jump on a
 * stone, but it must not jump into the water.
 *
 * Given a list of stones' positions (in units) in sorted ascending order,
 * determine if the frog is able to cross the river by landing on the last
 * stone. Initially, the frog is on the first stone and assume the first jump
 * must be 1 unit.
 * 
 * If the frog's last jump was k units, then its next jump must be either k - 1,
 * k, or k + 1 units. Note that the frog can only jump in the forward direction.
 *
 * Note:
 *
 * The number of stones is ≥ 2 and is < 1,100.
 * Each stone's position will be a non-negative integer < 231.
 * The first stone's position is always 0.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace {
   // Dummy hash operator for pair.
   struct pair_hash {
      template <class T1, class T2>
      std::size_t operator () (const std::pair<T1, T2> &p) const {
         auto h1 = std::hash<T1>{}(p.first);
         auto h2 = std::hash<T2>{}(p.second);
         return h1 ^ h2;
      }
   };

   class Solution {
      typedef std::pair<int, int>                                       T_PositionAndSpeed;
      typedef std::unordered_map<T_PositionAndSpeed, bool, pair_hash>   T_Cache;
      typedef std::unordered_set<int>                                   T_StoneSet;

   public:
      bool canCross(std::vector<int>& stones) const {
         if (stones.empty())
            return false;

         T_Cache cache;
         T_StoneSet stonesSet(stones.begin(), stones.end());
         return canCross(T_PositionAndSpeed(1, 1), stones.back(), stonesSet, cache);
      }
   private:
      bool canCross(T_PositionAndSpeed key, int targetPosition, const T_StoneSet& stonesSet, T_Cache& cache) const {
         auto it = cache.find(key);
         if (it != cache.end())
            return it->second;

         if (key.first == targetPosition)
            return addCache(cache, key, true);
         if (stonesSet.end() == stonesSet.find(key.first))
            return addCache(cache, key, false);
         if (key.first < 1 || key.second < 1 || key.first > targetPosition)
            return addCache(cache, key, false);

         return addCache(cache, key, 
               canCross(T_PositionAndSpeed(key.first + key.second - 1, key.second - 1), targetPosition, stonesSet, cache)
            || canCross(T_PositionAndSpeed(key.first + key.second,     key.second),     targetPosition, stonesSet, cache)
            || canCross(T_PositionAndSpeed(key.first + key.second + 1, key.second + 1), targetPosition, stonesSet, cache));
      }
      bool addCache(T_Cache& cache, T_PositionAndSpeed key, bool value) const {
         cache.insert(std::make_pair(key, value));
         return value;
      }
   };
}

TEST_CASE( "Frog Jump", "[test]" ) {
   Solution solver;

   CHECK(! solver.canCross(std::vector<int>{}));
   CHECK(solver.canCross(std::vector<int>{0, 1}));
   CHECK(solver.canCross(std::vector<int>{0, 1, 3, 5, 6, 8, 12, 17}));
   CHECK(! solver.canCross(std::vector<int>{0, 1, 2, 3, 4, 8, 9, 11}));
}
