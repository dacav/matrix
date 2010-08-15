#include <matrix/matrix.hpp>
#include <iostream>
#include <cassert>

using namespace std;

int main (int argc, char **argv)
{
	matrix::Matrix<unsigned> mx(3, 3);

    unsigned i, j;

    for (i = 0; i < 3; i ++) {
        for (j = 0; j < 3; j ++) {
            mx[i][j] = i * j;
        }
    }

    for (i = 0; i < 3; i ++) {
        for (j = 0; j < 3; j ++) {
            assert(mx[i][j] == (i * j));
        }
    }

}

