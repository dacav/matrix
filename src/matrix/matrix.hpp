#ifndef __defined_headers_matrix_hpp
#define __defined_headers_matrix_hpp

#include <stdexcept>

#include "vector.hpp"

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
            virtual ~Matrix ();

            RowAccess<T> operator[] (unsigned row);

            unsigned get_rows ();
            unsigned get_cols ();


        private:
            T & quick_access (unsigned row, unsigned col);

            unsigned rows;
            unsigned cols;
            T * values;
    };

}

#include "matrix.impl.hpp"

#endif // __defined_headers_matrix_hpp

