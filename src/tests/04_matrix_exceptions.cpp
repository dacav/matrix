#include <matrix/matrix.hpp>
#include <iostream>
#include <cassert>

using namespace std;

int main (int argc, char **argv)
{
	matrix::Matrix<unsigned> mx(3, 4);
	unsigned count = 0;

	try {
		mx[5][0] = 3;
	} catch (matrix::MatrixError &x) {
		count ++;
	}

	try {
		mx[0][5] = 3;
	} catch (matrix::MatrixError &x) {
		count ++;
	}

	exit(count == 2 ? EXIT_SUCCESS : EXIT_FAILURE);
}

