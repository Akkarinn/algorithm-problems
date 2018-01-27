/**
 * Source: https://leetcode.com/problems/max-points-on-a-line/description/
 * 
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 *
 */
#define CATCH_CONFIG_MAIN 
#pragma warning(push)
# pragma warning(disable : 4244)
# include <catch/catch.hpp>
#pragma warning(pop)

#include <leetcode/geometry/Point.hpp>

#include <vector>
#include <unordered_map>

using leetcode::geometry::Point;

namespace {

	class Solution {
		//copy-pasted
		struct pair_hash {
			template <class T1, class T2>
			std::size_t operator () (const std::pair<T1, T2> &p) const {
				auto h1 = std::hash<T1>{}(p.first);
				auto h2 = std::hash<T2>{}(p.second);
				return h1 ^ h2;
			}
		};

		typedef std::pair<int, int> Slope;
		typedef std::unordered_map<Slope, int, pair_hash> SlopeCount;

	public:
		int maxPoints(std::vector<Point>& points) const {
			if (points.empty())
				return 0;

			auto max_points = 1;
			// Sort points according to x and y
			std::sort(std::begin(points), std::end(points),
				[](const Point& a, const Point& b) {
				if (a.x != b.x)
					return a.x < b.x;
				return a.y < b.y;
			});
			// For each points, compute the slope with the others points.
			// A slope is identified according to the normalized pair of x-delta and y-delta from a source.
			// The identifier allow us to count the number of points on the same line starting
			// from a source.
			for (auto it = std::cbegin(points); it != std::cend(points); ++it) {
				const auto origin = *it;

				SlopeCount counts;
				auto nbDuplicate = 1;
				for (auto jt = std::next(it); jt != std::cend(points); ++jt) {
					const auto delta_x = jt->x - origin.x;
					const auto delta_y = jt->y - origin.y;

					if (delta_x == 0 && delta_y == 0) {
						++nbDuplicate;
					}
					else {
						auto d = pgcd(delta_x, delta_y);
						counts[Slope{ delta_x / d, delta_y / d }]++;
					}
				}

				auto mt = std::max_element(std::begin(counts), std::end(counts),
					[](const SlopeCount::value_type& p1, const SlopeCount::value_type& p2) {
					return p1.second < p2.second;
				});
				max_points = std::max(max_points, nbDuplicate + (mt != counts.end() ? mt->second : 0));
			}
			return max_points;
		}

	private:
		static int pgcd(int a, int b) {
			if (a == 0 && b == 0) return 1;
			if (a == 0) return b;
			if (b == 0) return a;
			while (b != 0) {
				auto c = a%b;
				a = b;
				b = c;
			}
			return a;
		}
	};
}

#define COMA ,

TEST_CASE( "Max Points on a Line", "[test]" ) {
   Solution solver;

   CHECK(0 == solver.maxPoints(std::vector<Point>{}));
   CHECK(1 == solver.maxPoints(std::vector<Point>{ Point{} }));
   CHECK(2 == solver.maxPoints(std::vector<Point>{ Point{} COMA Point{} }));
   CHECK(3 == solver.maxPoints(std::vector<Point>{ Point{} COMA Point{} COMA Point{} }));
   CHECK(3 == solver.maxPoints(std::vector<Point>{ Point{ 1, 1 } COMA Point{ 2, 2 } COMA Point{ 3, 3 } }));
   CHECK(3 == solver.maxPoints(std::vector<Point>{ Point{ 1, 1 } COMA Point{ 2, 2 } COMA Point{ 3, 3 } COMA Point{ 0, 1 } }));
   CHECK(2 == solver.maxPoints(std::vector<Point>{ Point{ 1, 1 } COMA Point{ 2, 2 } COMA Point{ 0, 2 } COMA Point{ 0, 1 } }));
   CHECK(3 == solver.maxPoints(std::vector<Point>{ Point{} COMA Point{ 1, 1 } COMA Point{ 0, 2 } COMA Point{ 0, 1 } }));
}
