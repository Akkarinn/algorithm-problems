#ifndef LEETCODE_GEOMETRY_POINT_HPP
#define LEETCODE_GEOMETRY_POINT_HPP

/**
 * Definition for 2D Point.
 *
 * Implementation from leetcode.
 */

namespace leetcode {
   namespace geometry {

	   struct Point {
		   int x;
		   int y;
		   Point() : x(0), y(0) {}
		   Point(int a, int b) : x(a), y(b) {}
	   };

   }
}

#endif
