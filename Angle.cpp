#include "pch.h"
#include "Angle.h"
#include "LinearMath.h"

namespace LinearAlgebra
{
	Angle Angle::fromRadians(double radiuns)
	{
		double val = radiuns;
		double degrees{ 0.0 };
		if (val < 0)
		{
			degrees = RadiansToDegrees(-val);
			degrees = 360 - degrees;
		}
		else
			degrees = RadiansToDegrees(val);
		return Angle(degrees);
	}

	Angle::Angle(double degFrac)
		:minutes{ 0.0 },
		seconds{0.0}
	{
		degrees = (int)degFrac;
		double fracdegree = degFrac - degrees;
		// how many minutes and seconds in fracdegree ?
		// TO DO
	}

	Angle::Angle(const Angle& other)
		: degrees{ other.getDegrees() },
		minutes{ other.getMinutes() },
		seconds{ other.getSeconds()}
	{
	}

	Angle::Angle(const double deg, const double min, const double sec)
	: degrees{ deg },
		minutes{ min},
		seconds{ sec}
	{
	}

	bool operator==(const Angle& l, const Angle& r)
	{
		return l.getDegrees() == r.getDegrees() &&
			l.getMinutes() == r.getMinutes() &&
			l.getSeconds() == r.getSeconds();
	}

	Angle operator+(Angle& l, Angle& r)
	{
		double deg = l.getDegrees() + r.getDegrees();
		double min = l.getMinutes() + r.getMinutes();
		double sec = l.getSeconds() + r.getSeconds();

		return Angle{ deg, min, sec };
	}
	Angle operator-(Angle& l, Angle& r)
	{
		double deg = l.getDegrees() - r.getDegrees();
		double min = l.getMinutes() - r.getMinutes();
		double sec = l.getSeconds() - r.getSeconds();

		return Angle{ deg, min, sec };
	}
	Angle operator*(Angle& l, const double factor)
	{
		double deg = l.getDegrees() * factor;
		double min = l.getMinutes() * factor;
		double sec = l.getSeconds() * factor;

		return Angle{ deg, min, sec };
	}

} // namespace LinearAlgebra

