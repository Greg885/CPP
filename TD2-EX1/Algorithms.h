//
// Created by grego on 02/10/2026.
//
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "SearchingAlgorithm.h"

class LinearSearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>& elements, int target) override;
};

class JumpSearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>& elements, int target) override;
};

class BinarySearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>& elements, int target) override;
};

#endif // ALGORITHMS_H