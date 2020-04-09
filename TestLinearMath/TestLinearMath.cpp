#include "pch.h"
#include "CppUnitTest.h"
#include "ComplexNumber.h"
#include "LinearMath.h"
#include "Angle.h"
#include "Matrix.h"
#include <vector>
#include "Determinants.h"
#include "Matrix.inl"
#include "Determinants.inl"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace LinearAlgebra;
using namespace LinearAlgebra::Determinants;

template
int LinearAlgebra::Determinants::determinant2x2<int>(const Matrix<int>& m);

namespace TestLinearMath
{
	TEST_CLASS(TestLinearMath)
	{
	public:
		
		TEST_METHOD(AddComplexNumbers)
		{
			Complex c1{ 10, 10 };
			Complex c2{ 10, 10 };
			Complex c3 = c1 + c2;
			Assert::AreEqual(c3.getReal(), 20.0);
			Assert::AreEqual(c3.getImaginary(), 20.0);
		}

		TEST_METHOD(SubtractComplexNumbers)
		{
			Complex c1{ 10, 10 };
			Complex c2{ 5, 5 };
			Complex c3 = c1 - c2;
			Assert::AreEqual(c3.getReal(), 5.0);
			Assert::AreEqual(c3.getImaginary(), 5.0);
		}

		TEST_METHOD(MultiplyComplexNumbers)
		{
			// K A Stroud Engineering Mathematics 3rd edition page 6
			Complex c1{ 3, 4 };
			Complex c2{ 2, 5 };
			Complex c3 = c1 * c2;
			Assert::AreEqual(c3.getReal(), -14.0);
			Assert::AreEqual(c3.getImaginary(), 23.0);
		}

		TEST_METHOD(ScalarDivComplexNumbers)
		{
			Complex c1{ 30, 40 };
			Complex c3 = c1/10;

			Assert::AreEqual(c3.getReal(), 3.0);
			Assert::AreEqual(c3.getImaginary(), 4.0);
		}

		TEST_METHOD(DivideComplexNumbers)
		{
			// K A Stroud Engineering Mathematics 3rd edition page 12
			Complex c1{ 7, -4 };
			Complex c2{ 4, 3 };
			Complex c3 = c1 / c2;

			Assert::AreEqual(c3.getReal(), 0.64);
			Assert::AreEqual(c3.getImaginary(), -1.48);
		}

		TEST_METHOD(GetComplexPolarAngleZero)
		{
			Complex c{ 12, 0 };
			Angle angle = c.angle();
			
			Assert::IsTrue(angle==Angle(0.0));
		}

		TEST_METHOD(GetComplexPolarAngleNinety)
		{
			Complex c{ 0, 1 };
			Angle angle = c.angle();
			Assert::IsTrue(angle==Angle(90.0));
		}

		TEST_METHOD(GetComplexPolarAngle)
		{
			Complex c{12, -5};
			Angle angle = c.angle();
			
			Assert::IsTrue(angle==Angle(337));
		}

		TEST_METHOD(GetComplexPolarRadius)
		{
			// K. A. Stroud Eng. Math. 3rd ed p 38
			Complex c{ 12, -5 };
			double radius = c.radius();
			radius = DecimalPlaces(radius, 2);
			Assert::AreEqual(radius, 13.0);
		}

		
		TEST_METHOD(Determinant2x2_Smoke)
		{ 
			std::vector<std::vector<int>> m{ std::vector<int>{ 6, 5 }, std::vector<int> { 1, 2 } };
			Matrix<int> matrix{ m };

			int res = ::determinant2x2<int>(m);
			Assert::AreEqual(res, 7);
		}

		TEST_METHOD(Determinant3x3_Smoke)
		{
		}

	};
}
