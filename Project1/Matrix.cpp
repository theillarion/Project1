#include "Matrix.hpp"

void Matrix::delete_matrix()
{
	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;
	
	matrix = nullptr;
	n = 0;
	m = 0;
}

void Matrix::initial_matrix()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] = 0;
}

Matrix::Matrix()
{
	matrix = nullptr;
	n = 0;
	m = 0;
}

Matrix::Matrix(const Matrix& matrix)
{
	n = matrix.n;
	m = matrix.m;
	this->matrix = new int* [n];
	
	for (int i = 0; i < n; i++)
		this->matrix[i] = new int[m];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			this->matrix[i][j] = matrix.matrix[i][j];
}

Matrix::Matrix(int	n, int	m) : n{ n }, m{ m }
{
	matrix = new int* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[m];
	
	initial_matrix();
}

Matrix::~Matrix()
{
	delete_matrix();
}

void Matrix::fill(int min, int max)
{
	srand(time(nullptr));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] = min + rand() % (max - 1);
}

void Matrix::fill(int** matrix)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			this->matrix[i][j] = matrix[i][j];
}

void Matrix::fill(int** matrix, int n, int m)
{
	delete_matrix();
	this->n = n;
	this->m = m;
	this->matrix = new int* [n];
	
	for (int i = 0; i < n; i++)
		this->matrix[i] = new int[m];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			this->matrix[i][j] = matrix[i][j];
}

Matrix& Matrix::operator=(const Matrix& right)
{
	if (this == &right)
		return (*this);

	delete_matrix();
	n = right.n;
	m = right.m;
	matrix = new int* [n];
	
	for (int i = 0; i < n; i++)
		matrix[i] = new int[m];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] = right.matrix[i][j];

	return (*this);
}

const Matrix operator +(const Matrix& left, const Matrix& right)
{
	if (left.n != right.n || left.m != right.m)
		throw "matrices have different sizes";

	Matrix	new_matrix(left.n, left.m);

	for (int i = 0; i < new_matrix.n; i++)
		for (int j = 0; j < new_matrix.m; j++)
			new_matrix.matrix[i][j] = left.matrix[i][j] + right.matrix[i][j];

	return (new_matrix);
}

const Matrix operator*(const Matrix& left, const Matrix& right)
{
	if (left.m != right.n)
		throw "the number of columns of the left matrix must be equal to the number of rows of the right matrix";

	Matrix	new_matrix(left.n, right.m);
	new_matrix.initial_matrix();

	for (int i = 0; i < left.n; i++)
		for (int j = 0; j < right.m; j++)
			for (int k = 0; k < left.m; k++)
				new_matrix.matrix[i][j] += left.matrix[i][k] * right.matrix[k][j];

	return (new_matrix);
}

std::ostream& operator<<(std::ostream& out, const Matrix& right)
{
	for (int i = 0; i < right.n; i++)
	{
		for (int j = 0; j < right.m; j++)
		{
			out << right.matrix[i][j];
			if (j != right.m - 1)
				out << " ";
		}
		out << std::endl;
	}
			
	return out;
}
