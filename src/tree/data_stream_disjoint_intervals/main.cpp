/**
 * Source: https://leetcode.com/problems/data-stream-as-disjoint-intervals/
 * 
 * Given a data stream input of non-negative integers a1, a2, ..., an, ...,
 * summarize the numbers seen so far as a list of disjoint intervals.
 *
 * For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ...,
 * then the summary will be:
 *
 * [1, 1]
 * [1, 1], [3, 3]
 * [1, 1], [3, 3], [7, 7]
 * [1, 3], [7, 7]
 * [1, 3], [6, 7]
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <algorithm>
#include <vector>

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool operator==(const Interval& lhs, const Interval& rhs) {
   return lhs.start == rhs.start && lhs.end == rhs.end;
}

std::ostream& operator<<(std::ostream& os, const Interval& i) {
   return os << "[" << i.start << ", " << i.end << "]";
}

typedef std::vector<Interval> Intervals;

namespace {

   class SummaryRanges {
   public:
      void addNum(int val) {
         Interval cur(val, val);
         // Get bounding intervals of the inserted value
         auto low = m_intervals.lower_bound(cur);
         auto up = low;
         if (low != m_intervals.begin())
            --low;

         Intervals results;
         // Check if we can merged with lower one
         if (low != m_intervals.end()) {
            auto merged = contigusMerge(*low, cur);
            std::copy(merged.begin(), merged.end(), std::back_inserter(results));
         }
         else {
            results.push_back(cur);
         }

         // Check if we can merged with upper one
         if (up != m_intervals.end()) {
            auto merged = contigusMerge(cur, *up);
            // Check if we can merged with lower one
            if (results.size() == 2) {
               if (merged.size() == 1)
                  results.back() = merged.front();
               else
                  results.push_back(merged.back());
            }
            else {
               if (merged.size() == 1)
                  results = Intervals{ {results.front().start, merged.front().end} };
               else
                  results.push_back(merged.back());
            }
         }
         // Remove the initial bounding intervals
         m_intervals.erase(low, (up == m_intervals.end() ? up : std::next(up)));
         // Add the resulting merged intervals
         m_intervals.insert(results.begin(), results.end());
      }

      Intervals getIntervals() const {
         return Intervals(m_intervals.begin(), m_intervals.end());
      }

   private:
      bool isIncluded(const Interval& dst, const Interval& src) const {
         return dst.start <= src.start && dst.end >= src.end;
      }
      Intervals contigusMerge(const Interval& left, const Interval& right) const {
         if (isIncluded(left, right))
            return {left};
         if (! IntervalCustomLess()(left, right))
            return contigusMerge(right, left);
         if (left.end + 1 == right.start)
            return {{left.start, right.end}};
         return {left, right};
      }

      struct IntervalCustomLess {
         bool operator()(const Interval& lhs, const Interval& rhs) const {
            if (lhs.end < rhs.start)
               return true;
            return false;
         }
      };
      std::set<Interval, IntervalCustomLess> m_intervals;
   };
}

#define COMA ,

TEST_CASE("Data Stream as Disjoint Intervals", "[test]") {
   {
      SummaryRanges solver;

      CHECK(solver.getIntervals() == Intervals{});
      solver.addNum(6);
      CHECK(solver.getIntervals() == Intervals{ { 6 COMA 6 } });
      solver.addNum(6);
      CHECK(solver.getIntervals() == Intervals{ { 6 COMA 6 } });
      solver.addNum(0);
      CHECK(solver.getIntervals() == Intervals{ { 0 COMA 0 } COMA { 6 COMA 6 } });
      solver.addNum(4);
      CHECK(solver.getIntervals() == Intervals{ { 0 COMA 0 } COMA { 4 COMA 4 } COMA { 6 COMA 6 } });
      solver.addNum(8);
      CHECK(solver.getIntervals() == Intervals{ { 0 COMA 0 } COMA { 4 COMA 4 } COMA { 6 COMA 6 } COMA { 8 COMA 8 } });
      solver.addNum(7);
      CHECK(solver.getIntervals() == Intervals{ { 0 COMA 0 } COMA { 4 COMA 4 } COMA { 6 COMA 8 } });
      solver.addNum(6);
      CHECK(solver.getIntervals() == Intervals{ { 0 COMA 0 } COMA { 4 COMA 4 } COMA { 6 COMA  8 } });
      solver.addNum(4);
      CHECK(solver.getIntervals() == Intervals{ { 0 COMA 0 } COMA { 4 COMA 4 } COMA { 6 COMA  8 } });
      solver.addNum(7);
      CHECK(solver.getIntervals() == Intervals{ { 0 COMA 0 } COMA { 4 COMA 4 } COMA { 6 COMA  8 } });
      solver.addNum(5);
      CHECK(solver.getIntervals() == Intervals{ { 0 COMA 0 } COMA { 4 COMA  8 } });
   }
   {
      SummaryRanges solver;

      CHECK(solver.getIntervals() == Intervals{});
      solver.addNum(1);
      CHECK(solver.getIntervals() == Intervals{ { 1 COMA 1 } });
      solver.addNum(1);
      CHECK(solver.getIntervals() == Intervals{ { 1 COMA 1 } });
      solver.addNum(0);
      CHECK(solver.getIntervals() == Intervals{ { 0 COMA 1 } });
      solver.addNum(2);
      CHECK(solver.getIntervals() == Intervals{ { 0 COMA 2 } });
      solver.addNum(1);
      CHECK(solver.getIntervals() == Intervals{ { 0 COMA 2 } });
      solver.addNum(15);
      CHECK(solver.getIntervals() == Intervals{ { 0 COMA 2 } COMA{ 15 COMA 15 } });
      solver.addNum(4);
      CHECK(solver.getIntervals() == Intervals{ { 0 COMA 2 } COMA{ 4 COMA 4 } COMA{ 15 COMA 15 } });
      solver.addNum(3);
      CHECK(solver.getIntervals() == Intervals{ { 0 COMA 4 } COMA{ 15 COMA 15 } });
      solver.addNum(8);
      CHECK(solver.getIntervals() == Intervals{ { 0 COMA 4 } COMA{ 8 COMA 8 } COMA{ 15 COMA 15 } });
      solver.addNum(7);
      CHECK(solver.getIntervals() == Intervals{ { 0 COMA 4 } COMA{ 7 COMA 8 } COMA{ 15 COMA 15 } });
      solver.addNum(6);
      CHECK(solver.getIntervals() == Intervals{ { 0 COMA 4 } COMA{ 6 COMA 8 } COMA{ 15 COMA 15 } });
      solver.addNum(5);
      CHECK(solver.getIntervals() == Intervals{ { 0 COMA 8 } COMA{ 15 COMA 15 } });
   }
}
