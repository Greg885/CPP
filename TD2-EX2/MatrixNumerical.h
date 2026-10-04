//
// Created by grego on 02/10/2026.
//
#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "MatrixBase.h"

template <typename T>
class MatrixNumerical : public MatrixBase<T> {
public:
    MatrixNumerical(size_t r, size_t c) : MatrixBase<T>(r, c) {}

    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other) const {
        if (this->rows != other.getRows() || this->cols != other.getCols())
            throw std::invalid_argument("Dimensions incompatibles pour l'addition");

        MatrixNumerical<T> result(this->rows, this->cols);
        for (size_t i = 0; i < this->rows; ++i) {
            for (size_t j = 0; j < this->cols; ++j) {
                result.addElement(i, j, this->data[i][j] + other.getElement(i, j));
            }
        }
        return result;
    }

    MatrixNumerical<T> operator-(const MatrixNumerical<T>& other) const {
        if (this->rows != other.getRows() || this->cols != other.getCols())
            throw std::invalid_argument("Dimensions incompatibles pour la soustraction");

        MatrixNumerical<T> result(this->rows, this->cols);
        for (size_t i = 0; i < this->rows; ++i) {
            for (size_t j = 0; j < this->cols; ++j) {
                result.addElement(i, j, this->data[i][j] - other.getElement(i, j));
            }
        }
        return result;
    }

    MatrixNumerical<T> operator*(const MatrixNumerical<T>& other) const {
        if (this->cols != other.getRows())
            throw std::invalid_argument("Dimensions incompatibles pour la multiplication");

        MatrixNumerical<T> result(this->rows, other.getCols());
        for (size_t i = 0; i < this->rows; ++i) {
            for (size_t j = 0; j < other.getCols(); ++j) {
                T sum = 0;
                for (size_t k = 0; k < this->cols; ++k) {
                    sum += this->data[i][k] * other.getElement(k, j);
                }
                result.addElement(i, j, sum);
            }
        }
        return result;
    }

    MatrixNumerical<T> getCoFactor(size_t p, size_t q, size_t n) const {
        MatrixNumerical<T> temp(n - 1, n - 1);
        size_t i = 0, j = 0;
        for (size_t row = 0; row < n; row++) {
            for (size_t col = 0; col < n; col++) {
                if (row != p && col != q) {
                    temp.addElement(i, j++, this->data[row][col]);
                    if (j == n - 1) {
                        j = 0;
                        i++;
                    }
                }
            }
        }
        return temp;
    }

    T getDeterminant(size_t n) const {
        if (this->rows != this->cols) throw std::logic_error("Matrice non carrée");
        if (n == 1) return this->data[0][0];
        if (n == 2) return this->data[0][0] * this->data[1][1] - this->data[0][1] * this->data[1][0];

        T D = 0;
        int sign = 1;
        for (size_t f = 0; f < n; f++) {
            MatrixNumerical<T> temp = getCoFactor(0, f, n);
            D += sign * this->data[0][f] * temp.getDeterminant(n - 1);
            sign = -sign; // Alterne le signe (+, -, +, -...)
        }
        return D;
    }

    MatrixNumerical<double> getInverse() const {
        size_t n = this->rows;
        T det = getDeterminant(n);
        if (det == 0) throw std::logic_error("Matrice singulière, pas d'inverse");

        MatrixNumerical<double> inv(n, n);
        int sign = 1;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                MatrixNumerical<T> temp = getCoFactor(i, j, n);
                sign = ((i + j) % 2 == 0) ? 1 : -1;
                // La transposition est faite en inversant i et j dans addElement
                inv.addElement(j, i, (sign * temp.getDeterminant(n - 1)) / static_cast<double>(det));
            }
        }
        return inv;
    }

    MatrixNumerical<double> operator/(const MatrixNumerical<T>& other) const {
        MatrixNumerical<double> thisDouble(this->rows, this->cols);
        for(size_t i = 0; i < this->rows; i++) {
            for(size_t j = 0; j < this->cols; j++) {
                thisDouble.addElement(i, j, static_cast<double>(this->data[i][j]));
            }
        }
        return thisDouble * other.getInverse();
    }

    static MatrixNumerical<T> getIdentity(int size) {
        MatrixNumerical<T> id(size, size);
        for (int i = 0; i < size; ++i) {
            id.addElement(i, i, 1);
        }
        return id;
    }
};

#endif // MATRIXNUMERICAL_H