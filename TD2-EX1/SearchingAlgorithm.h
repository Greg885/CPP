//
// Created by grego on 02/10/2026.
//
#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H

#include <vector>
#include <iostream>

class SearchingAlgorithm {
protected:
    int numberComparisons;

public:
    static int totalComparisons;
    static int totalSearch;
    static double averageComparisons;

    SearchingAlgorithm();
    virtual int search(const std::vector<int>& elements, int target) = 0;
    void displaySearchResults(std::ostream& os, int results, int target);
};

#endif // SEARCHINGALGORITHM_H