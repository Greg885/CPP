//
// Created by grego on 02/10/2026.
//
#include "SearchingAlgorithm.h"

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

SearchingAlgorithm::SearchingAlgorithm() : numberComparisons(0) {}

void SearchingAlgorithm::displaySearchResults(std::ostream& os, int results, int target) {
    totalComparisons += numberComparisons;
    totalSearch++;
    averageComparisons = static_cast<double>(totalComparisons) / totalSearch;

    os << "Recherche de la cible " << target << " : ";
    if (results != -1) {
        os << "Trouvée à l'indice " << results;
    } else {
        os << "Non trouvée";
    }
    os << " (Comparaisons: " << numberComparisons << ")" << std::endl;
}

