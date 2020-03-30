#include "pch.h"
#include "LinearMath.h"

#define Cpp17
#ifdef Cpp17
#define _USE_MATH_DEFINES // for C++
#include <cmath>
#else
#include <numbers>
#endif

namespace LinearAlgebra
{
	double DecimalPlaces(double d, int c)
	{
		int nd = (int)d;
		double frac = d - nd;
		int mult{ 1 };
		for (int i = 0; i < c; i++)
			mult *= 10;
		frac *= mult;
		int fd = (int)frac;

		double res = nd + ((double)fd / (double)mult);
		return res;
	}

	double SignificantFigs(double d, int c)
	{
		return d;
	}

	double RadiansToDegrees(double radians)
	{
#ifdef Cpp17
		return radians * 180 / M_PI;
#else
		return radians * 180 / std::numbers::pi;
#endif
	}

	double DegreesToRadians(double degrees)
	{
#ifdef Cpp17
		return degrees * M_PI/180;
#else
		return degrees * std::numbers::pi/180;
#endif
	}
}
