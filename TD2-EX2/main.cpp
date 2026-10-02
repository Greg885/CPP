//
// Created by grego on 02/10/2026.
//

#include <iostream>
#include "MatrixBase.h"
#include "MatrixNumerical.h"

int main() {
    try {
        MatrixNumerical<int> mat1(2, 2);
        mat1.addElement(0, 0, 3);
        mat1.addElement(0, 1, 7);
        mat1.addElement(1, 0, 2);
        mat1.addElement(1, 1, 6);

        std::cout << "Matrice 1 :" << std::endl;
        mat1.Display();

        std::cout << "\nDeterminant de la Matrice 1 : " << mat1.getDeterminant(2) << std::endl;

        MatrixNumerical<double> inv = mat1.getInverse();
        std::cout << "\nInverse de la Matrice 1 :" << std::endl;
        inv.Display();

        std::cout << "\nMatrice Identite (3x3) :" << std::endl;
        MatrixNumerical<int> id = MatrixNumerical<int>::getIdentity(3);
        id.Display();

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}