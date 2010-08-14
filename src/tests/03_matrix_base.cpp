#include <matrix/matrix.hpp>
#include <iostream>

using namespace std;

int main (int argc, char **argv)
{
	matrix::Matrix<int> mx(3, 3);

	cout << mx << endl;
}

