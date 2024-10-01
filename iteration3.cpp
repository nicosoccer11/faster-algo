#include "iteration3.h"
#include <iostream>
#include <stdexcept>

/**
 * Uses a static array to store characters within each sliding window
 * and checks for duplicates using a nested loop. 
 * This approach is generally faster than iteration 2 because 
 * we are using a static array instead of a dynamic vector.
 */

size_t iteration3(const std::string& input) {
    const size_t window_size = 14;

    // Iterate over the input with sliding windows of size 14
    for (size_t i = 0; i <= input.size() - window_size; ++i) {
        unsigned char arr[14] = {0}; // Array to store unique elements in the window
        size_t idx = 0; // Current index in the array
        bool is_unique = true; // Flag to check if window has all unique elements

        // Check each character in the window
        for (size_t j = 0; j < window_size; ++j) {
            unsigned char x = input[i + j];

            // Check if the element is already in the array
            for (size_t k = 0; k < idx; ++k) {
                if (arr[k] == x) {
                    is_unique = false; // Found a duplicate, break inner loop
                    break;
                }
            }

            if (!is_unique) {
                break; // No need to continue if we found a duplicate
            }

            // Add the unique element to the array
            arr[idx] = x;
            idx += 1;
        }

        // If all characters in the window are unique, return the position offset by 14
        if (is_unique) {
            return i + window_size;
        }
    }

    // If no valid window is found, throw an exception
    throw std::runtime_error("No valid window found");
}