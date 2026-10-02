//
// Created by grego on 28/09/2026.
//
#include <iostream>
#include "Complex2D.h"

int main() {
    std::cout << "--- Test des constructeurs ---" << std::endl;
    Complex2D c1(2.0, 3.0);
    Complex2D c2(1.0, 4.0);

    std::cout << "c1 = "; c1.afficher(); std::cout << std::endl;
    std::cout << "c2 = "; c2.afficher(); std::cout << std::endl;

    std::cout << "\n--- Test des operateurs ---" << std::endl;

    Complex2D addition = c1 + c2;
    std::cout << "c1 + c2 = "; addition.afficher(); std::cout << std::endl;

    Complex2D soustraction = c1 - c2;
    std::cout << "c1 - c2 = "; soustraction.afficher(); std::cout << std::endl;

    Complex2D multiplication = c1 * c2;
    std::cout << "c1 * c2 = "; multiplication.afficher(); std::cout << std::endl;

    std::cout << "\n--- Test des comparaisons ---" << std::endl;
    if (c1 > c2) {
        std::cout << "Le module de c1 est plus grand que celui de c2." << std::endl;
    } else {
        std::cout << "Le module de c1 n'est pas plus grand que celui de c2." << std::endl;
    }

    return 0;
}