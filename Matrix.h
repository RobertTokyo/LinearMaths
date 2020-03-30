#pragma once
#include <vector>

namespace LinearAlgebra
{
	template <class T>
	class Matrix
	{
	public:
		Matrix() {};
		Matrix(std::vector<std::vector<T>>);
		Matrix(Matrix<T>& other) {};

		std::pair<size_t, size_t> getDimensions();
		void addRow(std::vector<T> r);

	private:
		std::vector<std::vector<T>> matrix;
	};

	template<class T>
	T operator+(Matrix<T>& l, Matrix<T>& r);
	template<class T>
	T operator-(Matrix<T>& l, Matrix<T>& r);
	template<class T>
	T operator*(Matrix<T>& l, Matrix<T>& r);
	template<class T>
	T operator/(Matrix<T>& l, Matrix<T>& r);

	
}
