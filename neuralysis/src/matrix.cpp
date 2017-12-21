#include "matrix.h"
using namespace neuralysis;

matrix::matrix(const matrix& copy) : rows_(copy.get_rows()), columns_(copy.get_columns()) {
    values = new double*[get_rows()];
    for(unsigned int x = 0; x < get_rows(); x++) {
        values[x] = new double[get_columns()];
    }
    for(unsigned int x = 0; x < get_rows(); x++) {
        for(unsigned int y = 0; y < get_columns(); y++) {
            values[x][y] = copy[x][y];
        }
    }
}

matrix::matrix(unsigned int rows, unsigned int columns) : rows_(rows), columns_(columns) {
    values = new double*[get_rows()];
    for(unsigned int x = 0; x < get_rows(); x++) {
        values[x] = new double[get_columns()];
    }
}

matrix::~matrix() {
    for(unsigned int i = 0; i < rows_; i++) {
        delete values[i];
    }
    delete values;
}

unsigned int matrix::get_columns(void) const {
    return this->columns_;
}

unsigned int matrix::get_rows(void) const {
    return this->rows_;
}

matrix* matrix::transpose(void) const {
    matrix* m = new matrix(get_columns(), get_rows());
    for(unsigned int x = 0; x < m->get_rows(); x++) {
        for(unsigned int y = 0; y < m->get_columns(); y++) {
            (*m)[x][y] = values[y][x];
        }
    }
    return m;
}

matrix* matrix::operator*(const matrix& other) const {
    if(get_columns() != other.get_rows()) throw;
    matrix* m = new matrix(rows_, other.columns_);
    for(unsigned int x = 0; x < m->get_rows(); x++) {
        for(unsigned int y = 0; y < m->get_columns(); y++) {
                // Slight optimizaton to not initialize to 0
            (*m)[x][y] = values[x][0] * other[0][y];
            for(unsigned int i = 1; i < get_columns(); i++) {
                (*m)[x][y] += values[x][i] * other[i][y];
            }
        }
    }
    return m;
}

double* matrix::operator[](unsigned int i) const {
    return values[i];
}
