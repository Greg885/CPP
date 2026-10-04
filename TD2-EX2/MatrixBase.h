//
// Created by grego on 02/10/2026.
//

#ifndef MATRIXBASE_H
#define MATRIXBASE_H

#include <vector>
#include <iostream>
#include <stdexcept>

template <typename T>
class MatrixBase {
protected:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    MatrixBase(size_t r, size_t c) : rows(r), cols(c) {
        data.resize(r, std::vector<T>(c, T()));
    }

    void addElement(size_t r, size_t c, T value) {
        if (r < rows && c < cols) {
            data[r][c] = value;
        } else {
            throw std::out_of_range("Index hors limites");
        }
    }

    T getElement(size_t r, size_t c) const {
        if (r < rows && c < cols) {
            return data[r][c];
        }
        throw std::out_of_range("Index hors limites");
    }

    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    void Display(std::ostream& os = std::cout) const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                os << data[i][j] << "\t";
            }
            os << std::endl;
        }
    }
};

#endif // MATRIXBASE_H