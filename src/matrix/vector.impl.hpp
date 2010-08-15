#ifndef __defined_matrix_vector_impl_hpp
#define __defined_matrix_vector_impl_hpp

#include <cstdlib>

namespace matrix {

    template <typename T>
    Vector<T>::Vector (unsigned d)
    {
        unsigned i;

        dim = d;
        vals = new T[d];
        for (i = 0; i < d; i ++) {
            vals[i] = 0;
        }
    }

    template <typename T>
    Vector<T>::Vector (const Vector<T> &c)
    {
        vals = new T[c.dim];
        dim = c.dim;
        copy(c);
    }

    template <typename T>
    Vector<T> & Vector<T>::operator= (const Vector<T> &assign)
        throw (VectorError)
    {
        copy(assign);
        return *this;
    }

    template <typename T>
    Vector<T>::~Vector ()
    {
        delete[] vals;
    }

    template <typename T>
    T & Vector<T>::operator[] (unsigned i) const
        throw (VectorError)
    {
        if (i < dim) {
            return vals[i];
        } else {
            throw VectorError("Out of boundary");
        }
    }

    template <typename T>
    Vector<T> Vector<T>::operator+ (const Vector<T> &vec)
        throw (VectorError)
    {
        Vector<T> ret = *this;
        ret += vec;
        return ret;
    }

    template <typename T>
    Vector<T> & Vector<T>::operator+= (const Vector<T> &vec)
        throw (VectorError)
    {
        unsigned i;
        compatible(vec);
        for (i = 0; i < dim; i ++) {
            vals[i] += vec[i];
        }
        return *this;
    }

    template <typename T>
    Vector<T> Vector<T>::operator* (const T &val)
    {
        Vector<T> ret = *this;

        ret *= val;
        return ret;
    }

    template <typename T>
    Vector<T> & Vector<T>::operator*= (const T &val)
    {
        unsigned i;
        for (i = 0; i < dim; i ++) {
            vals[i] *= val;
        }
        return *this;
    }

    template <typename T>
    void Vector<T>::copy (const Vector<T> & src)
        throw (VectorError)
    {
        unsigned i;

        if (&src == this)
            return;

        compatible(src);
        for (i = 0; i < dim; i ++) {
            vals[i] = src[i];
        }
    }

    template <typename T>
    void Vector<T>::compatible (const Vector<T> &other)
        throw (VectorError)
    {
        if (other.dim != dim) {
            VectorError err("Incompatible size");
            throw err;
        }
    }

    template <typename T>
    std::ostream & operator<< (std::ostream &s, const Vector<T> &vec)
    {
        unsigned i;
        s << '<';
        for (i = 0; i < vec.dim - 1; i ++) {
            s << vec.vals[i] << ',';
        }
        s << vec.vals[i] << '>';
        return s;
    }
}

#endif // __defined_matrix_vector_impl_hpp

