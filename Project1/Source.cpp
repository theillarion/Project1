#include <iostream>
#include <fstream>
#include "Matrix.hpp"

using std::ifstream;
using std::string;
using std::endl;
using std::cout;


const Matrix	read_matrix_file(const string path)
{
	ifstream	file(path);
	Matrix		matrix;
	int**		__matrix;
	int			n = 0;
	int			m = 0;

	if (!file.is_open())
		throw "file isn't open";
	
	if (!file.eof())
		file >> n;
	if (!file.eof())
		file >> m;
	
	__matrix = new int* [n];
	for (int i = 0; i < n; i++)
		__matrix[i] = new int[m];
	
	for (int i = 0; i < n && !file.eof(); i++)
		for (int j = 0; j < m && !file.eof(); j++)
			file >> __matrix[i][j];
	
	matrix.fill(__matrix, n, m);
	
	return (matrix);
}

int main()
{
	Matrix matrix_file;
	Matrix matrix(4, 5);

	matrix_file = read_matrix_file("matrix.txt");
	matrix.fill(0, 100);
	
	cout << "A:" << endl << matrix_file << endl;
	cout << "B:" << endl << matrix << endl;

	try
	{
		cout << "A + B:" << endl << matrix_file + matrix << endl;
		cout << "A * B:" << endl << matrix_file * matrix << endl;
	}	
	catch (const char* exp)
	{
		cout << "Exception: " << exp << endl;
	}

	Matrix a(4, 5), b(5, 7);

	a.fill(0, 5);
	b.fill(0, 5);

	cout << "A:" << endl << a << endl;
	cout << "B:" << endl << b << endl;

	try
	{
		cout << "A * B" << endl << a * b << endl;
	}
	catch (const char* exp)
	{
		cout << "Exception: " << exp << endl;
	}
}
