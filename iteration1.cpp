#include "iteration1.h"
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stdexcept>

/**
 * Uses a set to store characters within each sliding window to ensure uniqueness.
 * If a unique window is found, it returns the index of the position offset by 14.
 */

size_t iteration1(const std::string& input) {

    // We are looking for a window of 14 elements
    const size_t window_size = 14;

    // Iterate over the input with sliding windows of size 14
    for (size_t i = 0; i <= input.size() - window_size; ++i) {

        // Create a set to check for uniqueness
        std::set<uint8_t> unique_elements(input.begin() + i, input.begin() + i + window_size);

        // If the set size is 14, then all elements in the window are unique
        if (unique_elements.size() == window_size) {
            return i + window_size;  // Return the position offset by 14
        }
    }

    // If no valid window is found, throw an exception or return an error value
    throw std::runtime_error("No valid window found");
}