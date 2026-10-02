//
// Created by grego on 28/09/2026.
//
#include <iostream>
#include "my_class.h"

// Implémentation du constructeur par défaut
my_class::my_class() {
    ma_chaine = "";
}

// Implémentation du constructeur avec argument
my_class::my_class(std::string texte) {
    ma_chaine = texte;
}

// Implémentation de la fonction d'affichage
void my_class::print_my_element() const {
    std::cout << ma_chaine << std::endl;
}
