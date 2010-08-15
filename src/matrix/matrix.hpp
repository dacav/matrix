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
    class Matrix
    {
        public:
            Matrix (unsigned rows, unsigned cols);
            virtual ~Matrix ();

            RowAccess<T> operator[] (unsigned row);

        private:
            unsigned rows;
            unsigned cols;
            T * values;
    };

}

#include "matrix.impl.hpp"

#endif // __defined_headers_matrix_hpp

