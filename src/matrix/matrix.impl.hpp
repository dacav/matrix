#ifndef __defined_headers_matrix_impl_hpp
#define __defined_headers_matrix_impl_hpp

#include <iostream>
using namespace std;

namespace matrix {

    template <typename T>
    Matrix<T>::Matrix (unsigned r, unsigned c)
    {
        values = new T[r * c];
        rows = r;
        cols = c;
    }

    template <typename T>
    Matrix<T>::~Matrix ()
    {
        delete[] values;
    }

    template <typename T>
    RowAccess<T>::RowAccess (T *vals, unsigned c)
        : values(vals), cols(c)
    {
    }

    template <typename T>
    T & RowAccess<T>::operator[] (unsigned i)
        throw (MatrixError)
    {
        if (i < cols) {
            return values[i];
        } else {
            throw MatrixError("Out of column boundary");
        }
    }

    template <typename T>
    RowAccess<T> Matrix<T>::operator[] (unsigned row)
    {
        if (row < rows) {
            return RowAccess<T>(values + cols * row, cols);
        } else {
            throw MatrixError("Out of row boundary");
        }
    }

}

#endif // __defined_headers_matrix_impl_hpp

