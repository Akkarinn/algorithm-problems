/**
 * Source: https://leetcode.com/problems/largest-rectangle-in-histogram/
 * 
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the histogram.
 * 
 * For example,
 * Given heights = [2,1,5,6,2,3],
 * return 10.
 */
#define CATCH_CONFIG_MAIN 
#pragma warning(push)
# pragma warning(disable : 4244)
# include <catch/catch.hpp>
#pragma warning(pop)

#include <stack>
#include <vector>

namespace {

   class Solution {
	   struct Element {
		   Element(int idx, int h) : idx(idx), h(h) {}
		   int idx;
		   int h;
	   };
	   typedef std::stack<Element> T_IncreasingHeights;
   public:
		int largestRectangleArea(std::vector<int> heights) const {
			if (heights.empty())
				return 0;

			auto areaMax = heights.front();
			heights.push_back(0); // ending sentinel

			T_IncreasingHeights stack;
			stack.push(Element{ -1, 0 }); // ending sentinel
			stack.push(Element{ 0, heights.front() });

			// Compute max square in all increase sequences
			for (std::size_t i = 1u; i < heights.size(); ++i) {
				const Element elt{ static_cast<int>(i), heights[i] };

				while (elt.h < stack.top().h) {
					auto prevElt = stack.top();
					stack.pop();
					auto areaPrevElt = prevElt.h * (elt.idx - stack.top().idx - 1);
					areaMax = std::max(areaMax, areaPrevElt);
				}
				stack.push(elt);
			}
			return areaMax;
      }
   };
}

#define COMA ,

TEST_CASE( "Largest Rectangle in Histogram", "[test]" ) {
   Solution solver;

   CHECK(0 == solver.largestRectangleArea(std::vector<int>{}));
   CHECK(1 == solver.largestRectangleArea(std::vector<int>{ 1 }));
   CHECK(2 == solver.largestRectangleArea(std::vector<int>{ 2 }));
   // Increasing order
   CHECK(6 == solver.largestRectangleArea(std::vector<int>{ 1, 2, 3, 5 }));
   // Decreasing order
   CHECK(8 == solver.largestRectangleArea(std::vector<int>{ 5, 4, 2, 1 }));
   // Same height
   CHECK(2 == solver.largestRectangleArea(std::vector<int>{ 1 COMA 1 }));
   CHECK(2 == solver.largestRectangleArea(std::vector<int>{ 2 COMA 1 }));
   CHECK(3 == solver.largestRectangleArea(std::vector<int>{ 1 COMA 1 COMA 1}));
   // Line
   CHECK(3 == solver.largestRectangleArea(std::vector<int>{ 2 COMA 1 COMA 2 }));
   CHECK(6 == solver.largestRectangleArea(std::vector<int>{ 1 COMA 3 COMA 3 COMA 1 }));
   // Complex order
   CHECK(7 == solver.largestRectangleArea(std::vector<int>{ 2 COMA 1 COMA 2 COMA 1 COMA 1 COMA 2 COMA 3}));
   CHECK(10 == solver.largestRectangleArea(std::vector<int>{ 2 COMA 1 COMA 5 COMA 6 COMA 2 COMA 3 }));
}
