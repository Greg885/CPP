//
// Created by grego on 02/10/2026.
//
#include <iostream>
#include <vector>
#include "Algorithms.h"

int main() {
    std::vector<int> data = {1, 3, 5, 7, 9, 11, 15, 18, 21, 25};
    int target = 15;

    LinearSearch ls;
    int resLs = ls.search(data, target);
    ls.displaySearchResults(std::cout, resLs, target);

    BinarySearch bs;
    int resBs = bs.search(data, target);
    bs.displaySearchResults(std::cout, resBs, target);

    std::cout << "Moyenne des comparaisons globale : " << SearchingAlgorithm::averageComparisons << std::endl;

    return 0;
}