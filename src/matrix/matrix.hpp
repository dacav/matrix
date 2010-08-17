#ifndef __defined_headers_matrix_hpp
#define __defined_headers_matrix_hpp

#include <stdexcept>

namespace matrix {

    class MatrixError : public std::logic_error
    {
        public:
            MatrixError (const char *msg) : std::logic_error(msg) {}
    };

    template <typename T> class RowAccess;

    template <typename T>
    class Matrix
    {
        public:
            Matrix (unsigned rows, unsigned cols);
            Matrix (const Matrix<T> &copy);

            virtual ~Matrix ();

            Matrix<T> & operator= (const Matrix<T> &copy)
                throw (MatrixError);
            RowAccess<T> operator[] (unsigned row) const
                throw (MatrixError);

            unsigned get_rows () const;
            unsigned get_cols () const;

            Matrix<T> operator* (const Matrix<T> &mx)
                throw (MatrixError);

        protected:
            T & quick_access (unsigned row, unsigned col) const;

            void copy (const Matrix<T> &c);

            unsigned rows;
            unsigned cols;
            T * values;
    };

}

#include "matrix.impl.hpp"

#endif // __defined_headers_matrix_hpp

