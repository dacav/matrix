#ifndef __defined_headers_matrix_impl_hpp
#define __defined_headers_matrix_impl_hpp

#include <algorithm>

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
    Matrix<T>::Matrix (const Matrix<T> &mx)
    {
        copy(mx);
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
    RowAccess<T> Matrix<T>::operator[] (unsigned row) const
        throw (MatrixError)
    {
        if (row < rows) {
            return RowAccess<T>(values + cols * row, cols);
        } else {
            throw MatrixError("Out of row boundary");
        }
    }

    template <typename T>
    unsigned Matrix<T>::get_rows () const
    {
        return rows;
    }

    template <typename T>
    unsigned Matrix<T>::get_cols () const
    {
        return cols;
    }

    template <typename T>
    T & Matrix<T>::quick_access (unsigned r, unsigned c) const
    {
        return values[cols * r + c];
    }

    template <typename T>
    Matrix<T> & Matrix<T>::operator= (const Matrix<T> &mx)
        throw (MatrixError)
    {
        if (rows == mx.rows && cols == mx.cols) {
            copy(mx);
            return *this;
        } else {
            throw MatrixError("Incompatible matrix product");
        }
    }

    template <typename T>
    void Matrix<T>::copy (const Matrix<T> &mx)
    {
        if (&mx != this) {
            const unsigned size = mx.rows * mx.cols;

            values = new T[size];
            
            std::copy(mx.values, mx.values + size, values);
            rows = mx.rows;
            cols = mx.cols;
        }
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator* (const Matrix<T> &mx)
        throw (MatrixError)
    {
        if (cols != mx.get_rows()) {
            throw MatrixError("Incompatible matrix product");
        } else {
            unsigned i, j, k;
            const unsigned cs = mx.get_cols();
            Matrix<T> ret(rows, cs);

            for (i = 0; i < rows; i ++) {
                for (j = 0; j < cs; j ++) {
                    T value = T();

                    for (k = 0; k < cols; k ++) {
                        value += quick_access(i, k) * mx.quick_access(k, j);
                    }
                    ret[i][j] = value;
                }
            }

            return ret;
        }
    }

}

#endif // __defined_headers_matrix_impl_hpp

