#pragma once

#ifndef __HH__LINEAR_ALGEBRA_DETERMINANTS_DEFINED
#define __HH__LINEAR_ALGEBRA_DETERMINANTS_DEFINED

#include <vector>
#include "Matrix.h"

namespace LinearAlgebra
{
	namespace Determinants
	{
		template <class T>
		T determinant2x2(const Matrix<T>& matrix);
		template <class T>
		T determinant3x3(const Matrix<T>& matrix);
	} // namespace Determinants
}// namespace LinearAlgrebra

#endif //__HH__LINEAR_ALGEBRA_DETERMINANTS_DEFINED

// End of file
