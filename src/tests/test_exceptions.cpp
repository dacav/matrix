#include <cassert>
#include <matrix/vector.hpp>

using namespace std;

int main (int argc, char **argv)
{
    matrix::Vector<int> v(5);
    matrix::Vector<int> w(3);
    int excount = 0;

    try {
        v[50] = 3;
    } catch (matrix::VectorError &err) {
        excount ++;
    }

    try {
        v = w;
    } catch (matrix::VectorError &err) {
        excount ++;
    }

    try {
        v = v + w;
    } catch (matrix::VectorError &err) {
        excount ++;
    }

    if (excount != 3) {
        exit(EXIT_FAILURE);
    } else {
        exit(EXIT_SUCCESS);
    }
}

