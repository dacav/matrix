#include <matrix/matrix.hpp>
#include <cassert>

#include <iostream>

int main (int argc, char **argv)
{
    matrix::Matrix<int> a (2, 3);
    matrix::Matrix<int> b (3, 1);

    a[0][0] = 0;
    a[0][1] = 1;
    a[0][2] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    a[1][2] = 5;

    b[0][0] = 6;
    b[1][0] = 7;
    b[2][0] = 8;

    matrix::Matrix<int> c = a * b;

    assert(c.get_rows() == 2);
    assert(c.get_cols() == 1);
    assert(c[0][0] == 23);
    assert(c[1][0] == 86);
}

