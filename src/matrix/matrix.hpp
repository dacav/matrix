#ifndef __defined_headers_matrix_hpp
#define __defined_headers_matrix_hpp

#include "vector.hpp"

namespace matrix {

    template <typename T>
    class Matrix : public Vector<Vector<T> *>
    {
        public:
            Matrix (unsigned ncols, unsigned nrows);
            Vector<T> & operator[] (unsigned row);
        private:
            unsigned nrows;
    };

}

#include "matrix.impl.hpp"

#endif // __defined_headers_matrix_hpp

