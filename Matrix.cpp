#include "pch.h"
#include "Matrix.h"

namespace LinearAlgebra
{
	template<class T>
	Matrix<T>::Matrix(std::vector<std::vector<T>> m)
	{
		for (auto r : m)
			addRow(r);
	}

	template<class T>
	std::pair<size_t, size_t> Matrix<T>::getDimensions()
	{
		size_t cols = matrix.size();
		size_t rows{};
		for (std::vector<T> v : matrix)
		{
			size_t n = v.size();
			if (n > rows)
				rows = n;
		}
		return std::make_pair(rows, cols);
	}

	template<class T>
	void Matrix<T>::addRow(std::vector<T> row)
	{
		matrix.push_back(row);
	}

	template<class T>
	T operator+(const Matrix<T>& l, const Matrix<T>& r)
	{
		std::pair<size_t, size_t> dimL = l.getDimensions();
		std::pair<size_t, size_t> dimR = l.getDimensions();
		if (dimL.first != dimR.first || dimL.second != dimR.second)
			throw std::exception("matrices are not complient");
		
		Matrix<T> res;
		for (size_t i = 0; i < dimL.first; i++)
		{
			std::vector<T> row;
			for (size_t j = 0; j < dimL.second; j++)
			{
				row.push_back(l[i][j] + r[i][j]);
			}
			res.addRow(row);
		}
		return res;
	}

	template<class T>
	T operator-(Matrix<T>& l, Matrix<T>& r)
	{
		std::pair<size_t, size_t> dimL = l.getDimensions();
		std::pair<size_t, size_t> dimR = l.getDimensions();
		if (dimL.first != dimR.first || dimL.second != dimR.second)
			throw std::exception("matrices are not complient");

		Matrix<T> res;
		for (size_t i = 0; i < dimL.first; i++)
		{
			std::vector<T> row;
			for (size_t j = 0; j < dimL.second; j++)
			{
				row.push_back(l[i][j] - r[i][j]);
			}
			res.addRow(row);
		}
		return res;
	}

	template<class T>
	T operator*(Matrix<T>& l, Matrix<T>& r)
	{
		std::pair<size_t, size_t> dimL = l.getDimensions();
		std::pair<size_t, size_t> dimR = l.getDimensions();
		if (dimL.first != dimR.first || dimL.second != dimR.second)
			throw std::exception("matrices are not complient");

		Matrix<T> res;
		for (size_t i = 0; i < dimL.first; i++)
		{
			std::vector<T> row;
			for (size_t j = 0; j < dimL.second; j++)
			{
				row.push_back(l[i][j] * r[i][j]);
			}
			res.addRow(row);
		}
		return res;
	}

	template<class T>
	T operator/(Matrix<T>& l, Matrix<T>& r)
	{
		std::pair<size_t, size_t> dimL = l.getDimensions();
		std::pair<size_t, size_t> dimR = l.getDimensions();
		if (dimL.first != dimR.first || dimL.second != dimR.second)
			throw std::exception("matrices are not complient");

		Matrix<T> res;
		for (size_t i = 0; i < dimL.first; i++)
		{
			std::vector<T> row;
			for (size_t j = 0; j < dimL.second; j++)
			{
				row.push_back(l[i][j] / r[i][j]);
			}
			res.addRow(row);
		}
		return res;
	}

}//LinearAlgebra

//End of file
