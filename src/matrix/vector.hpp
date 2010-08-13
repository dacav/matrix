#ifndef __defined_matrix_vector_hpp
#define __defined_matrix_vector_hpp

#include <iostream>
#include <stdexcept>

namespace matrix {

    class VectorError : public std::logic_error
    {
        public:
            VectorError (const char *msg) : std::logic_error(msg) {}
    };

    template <typename T>
    class Vector
    {
        public:
            Vector (unsigned dim);
            Vector (const Vector &c);

            virtual ~Vector ();

            T & operator[] (unsigned i) const throw (VectorError);

            Vector<T> operator+ (const Vector<T> &vec)
                throw (VectorError);
            Vector<T> & operator+= (const Vector<T> &vec)
                throw (VectorError);

            Vector<T> operator* (const T &val);
            Vector<T> & operator*= (const T &val);

            Vector<T> & operator= (const Vector<T> &assign)
                throw (VectorError);

            template <typename Tf>
            friend std::ostream & operator<< (std::ostream &s,
                                              const Vector<Tf> &vec);

        private:
            T * vals;
            unsigned dim;

            void compatible (const Vector<T> &other) throw (VectorError);
            void copy (const Vector<T> & src) throw (VectorError);
    };

}

#include <matrix/vector.impl.hpp>

#endif // __defined_matrix_vector_hpp

