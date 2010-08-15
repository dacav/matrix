#include <matrix/matrix.hpp>
#include <iostream>
#include <cassert>

using namespace std;

static
unsigned hash (unsigned r, unsigned c)
{
	return (r << 2) * (c + 1);
}

int main (int argc, char **argv)
{
	matrix::Matrix<unsigned> mx(3, 4);

    unsigned r, c;

    for (r = 0; r < mx.get_rows(); r ++) {
        for (c = 0; c < mx.get_cols(); c ++) {
            mx[r][c] = hash(r, c);
        }
    }

    for (r = 0; r < mx.get_rows(); r ++) {
        for (c = 0; c < mx.get_cols(); c ++) {
            assert(mx[r][c] == hash(r, c));
        }
    }

}

