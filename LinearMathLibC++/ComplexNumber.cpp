#include "pch.h"
#include "ComplexNumber.h"
#include "Angle.h"

#include  <exception>

namespace LinearAlgebra
{
	Angle Complex::angle()
	{
		double res = atan(abs(imaginary) / real);
		if (imaginary < 0)
			res = -res;
		return Angle::fromRadians(res);
	}

	double Complex::radius()
	{
		return (sqrt(real*real + imaginary * imaginary));
	}

	Complex Complex::conjugate()
	{
		return Complex(real, -imaginary);
	}

	Complex operator+(Complex& l, Complex& r)
	{
		return Complex{ l.getReal() + r.getReal(), l.getImaginary() + r.getImaginary() };
	}

	Complex operator-(Complex& l, Complex& r)
	{
		return Complex{ l.getReal() - r.getReal(), l.getImaginary() - r.getImaginary() };
	}

	Complex operator*(Complex& l, double scalar)
	{
		return Complex{ l.getReal()*scalar, l.getImaginary()*scalar };
	}

	Complex operator*(Complex& l, Complex& r)
	{
		//K A Stroud Engineering Mathematics Page 6
		double lr = l.getReal();
		double li = l.getImaginary();
		double rr = r.getReal();
		double ri = r.getImaginary();

		double reals = lr * rr;
		double mixed = rr * li + ri * lr;
		double imgs = li * ri;
	
		return Complex{ reals - imgs, mixed};
	}

	Complex operator/(Complex& l, double scalar)
	{
		return Complex{ l.getReal()/scalar, l.getImaginary()/scalar };
	}

	Complex operator/(Complex& l, Complex& r)
	{
		Complex conjfactor = r.conjugate();
		Complex denomin = r * conjfactor;
		Complex numerator = l * conjfactor;
		return numerator / denomin.getReal();
	}
}