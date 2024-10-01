#include "iteration5.h"
#include <iostream>
#include <stdexcept>

/**
 * We improve upon iteration 4 by reducing unnecessary computations.
 * In `iteration4`, the filter is updated by XORing both the first and last characters in each window.
 * This leads to redundant XOR operations and multiple updates per window.
 * In contrast, iteration5 uses a single pass with a more sophisticated bitwise mechanism, 
 * tracking characters only once and reducing the need to "undo" changes like in iteration4.
 * This results in fewer operations and better overall performance.
 * Credit to https://github.com/david-a-perez for this solution
 */

size_t iteration5(const std::string& input) {
    size_t idx = 0;
    const size_t window_size = 14;

    while (idx + window_size <= input.size()) {
        uint32_t state = 0;

        // Get a slice of 14 bytes from the input starting at idx
        bool found_duplicate = false;
        size_t pos = 0;

        // Iterate over the slice to check for duplicates
        for (size_t i = 0; i < window_size; ++i) {
            uint8_t byte = input[idx + i];
            uint8_t bit_idx = byte % 32;

            // Check if this bit is already set
            if (state & (1 << bit_idx)) {
                found_duplicate = true;
                pos = i;
                break;
            }

            // Set the bit to mark this byte as seen
            state |= (1 << bit_idx);
        }

        // If we found a duplicate, move idx forward by the position of the duplicate + 1
        if (found_duplicate) {
            idx += pos + 1;
        }
        // If all characters are unique, check if there are exactly 14 unique bits
        else if (__builtin_popcount(state) == 14) { // `__builtin_popcount` counts the 1s in `state`
            return idx;
        }
    }
}