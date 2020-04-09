#include "pch.h"
#include "Determinants.h"

namespace LinearAlgebra
{
	namespace Determinants
	{
		template<class T>
		T determinant2x2(const Matrix<T>& matrix)
		{
			// K A Stround Engineering Mathematics 3rd Edition page 102 
			T res{};
			const std::pair<size_t, size_t> dim = matrix.getDimensions();
			if (dim.first == 2 && dim.second == 2)
			{
				double l = matrix[0][0] * matrix[1][1];
				double r = matrix[0][1] * matrix[1][0];
				res = static_cast<T>(l - r);
			}
			else
				throw std::exception("Not a square 2x2 matrix");

			return res;
		}

		template<class T>
		T determinant3x3(const Matrix<T>& matrix)
		{
			// K A Stround Engineering Mathematics 3rd Edition page 110 is 3x3 matrix
			T res{};
			if (matrix.size() == 3 && matrix[0].size() == 3 && matrix[1].size() == 3)
			{
				Matrix<T> m1;
				m1.addRow(std::vector{ matrix[1][1], matrix[2][1] });
				m1.addRow(std::vector{ matrix[1][2], matrix[2][2] });

				Matrix<T> m2;
				m1.addRow(std::vector{ matrix[0][1], matrix[2][1] });
				m1.addRow(std::vector{ matrix[0][2], matrix[2][2] });

				Matrix<T> m3;
				m1.addRow(std::vector{ matrix[0][0], matrix[0][1] });
				m1.addRow(std::vector{ matrix[1][1], matrix[1][2] });

				res = deteminant2x2(m1)*matrix[0][0] - deteminant2x2(m2)*matrix[0][1] + deteminant2x2(m3)*matrix[0][2];
			}
			else
				throw std::exception("Not a square 3x3 matrix");

			return res;
		}
	}
}