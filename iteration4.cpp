#include "iteration4.h"
#include <iostream>
#include <stdexcept>

/**
 * Checks for unique characters in a sliding window of 14 elements using bitwise XOR and a bitmask filter.
 * The bitmask tracks the uniqueness of characters mod 32 within the window by toggling bits on or off.
 * This approach leverages the CPU's ability to perform bitwise operations extremely efficiently,
 * as these operations (XOR, bit shifts) are much faster than dynamic data structures like hash sets or vectors,
 * avoiding cache misses and memory allocations.
 * Credit to https://x.com/_B_3_N_N_Y_ for this solution.
 */

size_t iteration4(const std::string& input) {
    uint32_t filter = 0;  // 32-bit filter to track uniqueness of characters
    const size_t window_size = 14;

    // Precompute the filter for the first 13 characters
    for (size_t i = 0; i < window_size - 1; ++i) {
        filter ^= 1 << (input[i] % 32);
    }

    // Iterate over the input with sliding windows of size 14
    for (size_t i = 0; i <= input.size() - window_size; ++i) {
        unsigned char first = input[i];                 // First character in the window
        unsigned char last = input[i + window_size - 1]; // Last character in the window

        // Update filter by XORing the last character of the window
        filter ^= 1 << (last % 32);

        // Check if the filter has 14 unique bits set
        if (__builtin_popcount(filter) == window_size) {
            return i + window_size;  // Return the position offset by 14 if unique
        }

        // Undo the XOR for the first character of the previous window
        filter ^= 1 << (first % 32);
    }

    // If no valid window is found, throw an exception
    throw std::runtime_error("No valid window found.");
}