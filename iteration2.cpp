#include "iteration2.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

/**
 * Uses a vector to store characters within each sliding window
 * and checks for duplicates using a nested loop. 
 * faster than iteration 1 because adding and checking a list 
 * is faster than a hashset on a small scale
 */

size_t iteration2(const std::string& input) {
    const size_t window_size = 14;

    // Iterate over the input with sliding windows of size 14
    for (size_t i = 0; i <= input.size() - window_size; ++i) {
        std::vector<unsigned char> vec;  // Vector to store unique elements in the window
        vec.reserve(window_size);       // Reserve capacity for 14 elements
        bool is_unique = true;          // Flag to track uniqueness

        for (size_t j = 0; j < window_size; ++j) {
            unsigned char x = input[i + j];

            // Check if the element is already in the vector
            if (std::find(vec.begin(), vec.end(), x) != vec.end()) {
                is_unique = false;  // Found a duplicate
                break;
            }

            vec.push_back(x);  // Add the unique element to the vector
        }

        // If the window is unique, return the position offset by 14
        if (is_unique) {
            return i + window_size;
        }
    }

    // If no valid window is found, throw an exception
    throw std::runtime_error("No valid window found");
}