#pragma once

#ifndef __HH__LINEAR_ALGEBRA_COMPLEX_DEFINED
#define __HH__LINEAR_ALGEBRA_COMPLEX_DEFINED

#include "Angle.h"

namespace LinearAlgebra
{

	class Complex
	{
	public:
		Complex() = delete;

		Complex(double r, double i)
			: real{ r },
			imaginary{ i }
		{};

		double getReal() const { return real; };
		double getImaginary() const { return imaginary; };

		Angle angle();
		double radius();

		Complex conjugate();

	protected:
		double real;
		double imaginary;


	};

	Complex operator+(Complex& l, Complex& r);
	Complex operator-(Complex& l, Complex& r);
	Complex operator*(Complex& l, double scalar);
	Complex operator*(Complex& l, Complex& r);
	Complex operator/(Complex& l, double scalar);
	Complex operator/(Complex& l, Complex& r);
}

#endif // __HH__LINEAR_ALGEBRA_COMPLEX_DEFINED
//end of file

