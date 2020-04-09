#pragma once
#include <vector>

namespace LinearAlgebra
{
	template <class T>
	class Matrix
	{
	public:
		/*explicit*/ Matrix()  {};
		/*explicit*/ Matrix(std::vector<std::vector<T>>);
		/*explicit*/ Matrix(const Matrix<T>& other);

		std::pair<size_t, size_t> getDimensions() const;
		void addRow(std::vector<T> r);

		/*Matrix<T> operator+(const Matrix<T>& r);
		Matrix<T> operator-(Matrix<T>& r);
		Matrix<T> operator*(Matrix<T>& r);
		Matrix<T> operator/(Matrix<T>& r);
		*/
		const std::vector<T>& operator[](size_t index) const;

	private:
		std::vector<std::vector<T>> matrix;
	};

	template<class T>
	Matrix<T> operator+(const Matrix<T>& l, const Matrix<T>& r);
	template<class T>
	Matrix<T> operator-(Matrix<T>& l, Matrix<T>& r);
	template<class T>
	Matrix<T> operator*(Matrix<T>& l, Matrix<T>& r);
	template<class T>
	Matrix<T> operator/(Matrix<T>& l, Matrix<T>& r);	
}
