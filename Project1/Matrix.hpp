#pragma once
#include <cstdlib>
#include <ctime>
#include <ostream>


class Matrix
{
private:
	int	n;
	int	m;
	int	**matrix;
	void	delete_matrix();
	void	initial_matrix();
public:
	Matrix();
	Matrix(const Matrix& matrix);
	Matrix(int	n, int	m);
	~Matrix();
	void	fill(int	min, int	max);
	void	fill(int**	matrix);
	void	fill(int**	matrix, int	n, int	m);

	Matrix& operator =(const Matrix& right);
	friend const Matrix operator +(const Matrix& left, const Matrix& right);
	friend const Matrix operator *(const Matrix& left, const Matrix& right);
	friend std::ostream& operator <<(std::ostream& out, const Matrix& right);
};

