#include "matrix.h"
using namespace neuralysis;

matrix::matrix(const matrix& copy) : rows_(copy.get_rows()), columns_(copy.get_columns()) {
    this->values = new double*[this->get_rows()];
    for(unsigned int x = 0; x < this->get_rows(); x++) {
        this->values[x] = new double[this->get_columns()];
    }
    for(unsigned int x = 0; x < this->get_rows(); x++) {
        for(unsigned int y = 0; y < this->get_columns(); y++) {
            this->values[x][y] = copy[x][y];
        }
    }
}

matrix::matrix(unsigned int rows, unsigned int columns) : rows_(rows), columns_(columns) {
    this->values = new double*[this->get_rows()];
    for(unsigned int x = 0; x < this->get_rows(); x++) {
        this->values[x] = new double[this->get_columns()];
    }
}

matrix::~matrix() {
    for(unsigned int i = 0; i < this->get_rows(); i++) {
        delete this->values[i];
    }
    delete this->values;
}

unsigned int matrix::get_columns(void) const {
    return this->columns_;
}

unsigned int matrix::get_rows(void) const {
    return this->rows_;
}

matrix matrix::transpose(void) const {
    matrix m(this->get_columns(), this->get_rows());
    for(unsigned int x = 0; x < m.get_rows(); x++) {
        for(unsigned int y = 0; y < m.get_columns(); y++) {
            m[x][y] = this->values[y][x];
        }
    }
    return m;
}

double* matrix::operator[](const unsigned int i) const {
    return this->values[i];
}

matrix matrix::operator*(const matrix& other) const {
    if(this->get_columns() != other.get_rows()) throw;
    matrix m(this->get_rows(), other.get_columns());
    for(unsigned int x = 0; x < m.get_rows(); x++) {
        for(unsigned int y = 0; y < m.get_columns(); y++) {
                // Slight optimizaton to not initialize to 0
            m[x][y] = values[x][0] * other[0][y];
            for(unsigned int i = 1; i < this->get_columns(); i++) {
                m[x][y] += values[x][i] * other[i][y];
            }
        }
    }
    return m;
}

matrix matrix::operator+(const matrix& other) const {
    if(this->get_columns() != other.get_columns() || this->get_rows() != other.get_rows()) throw;
    matrix m(this->get_rows(), this->get_columns());
    for(unsigned int x = 0; x < m.get_rows(); x++) {
        for(unsigned int y = 0; y < m.get_columns(); y++) {
            m[x][y] = this->values[x][y] + other[x][y];
        }
    }
    return m;
}

matrix matrix::operator-(const matrix& other) const {
    if(this->get_columns() != other.get_columns() || this->get_rows() != other.get_rows()) throw;
    matrix m(this->get_rows(), this->get_columns());
    for(unsigned int x = 0; x < m.get_rows(); x++) {
        for(unsigned int y = 0; y < m.get_columns(); y++) {
            m[x][y] = this->values[x][y] - other[x][y];
        }
    }
    return m;
}

void matrix::operator=(const matrix& other) const {
    if(this->get_columns() != other.get_columns() || this->get_rows() != other.get_rows()) throw;
    for(unsigned int x = 0; x < this->get_rows(); x++) {
        for(unsigned int y = 0; y < this->get_columns(); y++) {
            this->values[x][y] = other[x][y];
        }
    }
}
