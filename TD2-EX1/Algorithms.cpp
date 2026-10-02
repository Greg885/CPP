//
// Created by grego on 02/10/2026.
//
#include "Algorithms.h"
#include <cmath>
#include <algorithm>

int LinearSearch::search(const std::vector<int>& elements, int target) {
    numberComparisons = 0;
    for (size_t i = 0; i < elements.size(); ++i) {
        numberComparisons++;
        if (elements[i] == target) {
            return i;
        }
    }
    return -1;
}

int JumpSearch::search(const std::vector<int>& elements, int target) {
    numberComparisons = 0;
    int n = elements.size();
    if (n == 0) return -1;

    int step = std::sqrt(n);
    int prev = 0;

    while (elements[std::min(step, n) - 1] < target) {
        numberComparisons++;
        prev = step;
        step += std::sqrt(n);
        if (prev >= n) return -1;
    }
    numberComparisons++;

    while (elements[prev] < target) {
        numberComparisons++;
        prev++;
        if (prev == std::min(step, n)) return -1;
    }
    numberComparisons++;

    if (elements[prev] == target) return prev;
    return -1;
}

int BinarySearch::search(const std::vector<int>& elements, int target) {
    numberComparisons = 0;
    int left = 0;
    int right = elements.size() - 1;

    while (left <= right) {
        numberComparisons++;
        int mid = left + (right - left) / 2;

        if (elements[mid] == target) return mid;

        numberComparisons++;
        if (elements[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
