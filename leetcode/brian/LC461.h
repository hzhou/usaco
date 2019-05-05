/*
Few minutes.
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Hamming Distance.
Memory Usage: 8.4 MB, less than 99.64% of C++ online submissions for Hamming Distance.

Not much to say. Took a little to find popcount in MSC because I still don't have gcc or g++ set up.
*/

#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x^y);
    }
};