/**
 * Source: https://leetcode.com/problems/reverse-bits/
 *
 * Reverse bits of a given 32 bits unsigned integer.
 * 
 * For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
 * 
 * Follow up:
 * If this function is called many times, how would you optimize it?
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>

#include <numeric>
#include <cstdint>

namespace {
    class Solution {
      unsigned char reverse(unsigned char c) {
         return
            (((c>>0) & 0x1) << 7) |
            (((c>>1) & 0x1) << 6) |
            (((c>>2) & 0x1) << 5) |
            (((c>>3) & 0x1) << 4) |
            (((c>>4) & 0x1) << 3) |
            (((c>>5) & 0x1) << 2) |
            (((c>>6) & 0x1) << 1) |
            (((c>>7) & 0x1) << 0);
      }
    public:
      uint32_t reverseBits(uint32_t n) {
         unsigned int result = 0;
        
         const unsigned char inByte0 = (n & 0xff);
         const unsigned char inByte1 = (n & 0xff00) >> 8;
         const unsigned char inByte2 = (n & 0xff0000) >> 16;
         const unsigned char inByte3 = (n & 0xff000000) >> 24;

         result = (reverse(inByte0) << 24) | (reverse(inByte1) << 16) | (reverse(inByte2) << 8) | reverse(inByte3);
         return result;
      }
   };
}

TEST_CASE( "Reverse bits", "[test]" ) {
    Solution solver;

    CHECK( solver.reverseBits(0) == 0 );
    CHECK( solver.reverseBits(1) == 0x80000000 );
    CHECK( solver.reverseBits(43261596) == 964176192 );
}
