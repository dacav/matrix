#ifndef __defined_headers_matrix_impl_hpp
#define __defined_headers_matrix_impl_hpp

#include <iostream>
using namespace std;

namespace matrix {

    template <typename T>
    class RowAccess
    {
        public:
            RowAccess (T * values, unsigned cols);
            T & operator[] (unsigned i) throw (MatrixError);
        private:
            T * values;
            unsigned cols;
    };

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

    template <typename T>
    unsigned Matrix<T>::get_rows ()
    {
        return rows;
    }

    template <typename T>
    unsigned Matrix<T>::get_cols ()
    {
        return cols;
    }

    template <typename T>
    T & Matrix<T>::quick_access (unsigned r, unsigned c)
    {
        return values[cols * r + c];
    }

}

#endif // __defined_headers_matrix_impl_hpp

