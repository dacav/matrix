#include <cassert>
#include <matrix/vector.hpp>

using namespace std;

int main (int argc, char **argv)
{
    matrix::Vector<int> v(5);

    int factor = 2;

    v[0] = 1;
    v[1] = 2;
    v[2] = 4;
    v[3] = 8;
    v[4] = 16;

    assert(v[0] == 1);
    assert(v[1] == 2);
    assert(v[2] == 4);
    assert(v[3] == 8);
    assert(v[4] == 16);

    matrix::Vector<int> w = v;

    assert(w[0] == 1);
    assert(w[1] == 2);
    assert(w[2] == 4);
    assert(w[3] == 8);
    assert(w[4] == 16);

    v = v * factor;

    assert(v[0] == 2*1);
    assert(v[1] == 2*2);
    assert(v[2] == 2*4);
    assert(v[3] == 2*8);
    assert(v[4] == 2*16);

    factor ++;
    w *= factor;

    assert(w[0] == 3*1);
    assert(w[1] == 3*2);
    assert(w[2] == 3*4);
    assert(w[3] == 3*8);
    assert(w[4] == 3*16);

    w += v;
    assert(w[0] == (3+2)*1);
    assert(w[1] == (3+2)*2);
    assert(w[2] == (3+2)*4);
    assert(w[3] == (3+2)*8);
    assert(w[4] == (3+2)*16);

    exit(EXIT_SUCCESS);
}

