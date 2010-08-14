#ifndef __defined_headers_matrix_impl_hpp
#define __defined_headers_matrix_impl_hpp

namespace matrix {

    template <typename T>
    Matrix<T>::Matrix (unsigned nc, unsigned nr)
             : Vector<Vector<T> *>(nc)
    {
        unsigned i;

        nrows = nc;
        for (i = 0; i < nc; i ++) {
            Vector<Vector<T> *>::operator[](i) = new Vector<T>(nr);
        }
    }

    template <typename T>
    Vector<T> & Matrix<T>::operator[] (unsigned row)
    {
        Vector<T> *ret;

        ret = Vector<Vector<T> *>::operator[](row);
        return *ret;
    }

}

#endif // __defined_headers_matrix_impl_hpp

