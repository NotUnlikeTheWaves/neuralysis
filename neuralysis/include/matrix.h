#ifndef NEURALYSIS_MATRIX_H
#define NEURALYSIS_MATRIX_H

namespace neuralysis {
    class matrix {
    public:
        matrix(unsigned int rows, unsigned int columns);
        matrix(const matrix& copy);
        ~matrix();
        unsigned int get_columns(void) const;
        unsigned int get_rows(void) const;
        matrix* transpose(void) const;
        matrix* operator*(const matrix& other) const;
        double* operator[](unsigned int i) const;

    private:
        double** values;
        const unsigned int rows_;
        const unsigned int columns_;
    };
}

#endif