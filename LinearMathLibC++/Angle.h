#pragma once

namespace LinearAlgebra
{
#ifndef __HH_LINEAR_ALGEBRA_ANGLE_HH
#define __HH_LINEAR_ALGEBRA_ANGLE_HH
	class Angle
	{
	public:
		static Angle fromRadians(double radiuns);
		Angle() = delete;
		Angle(double angle);
		Angle(const Angle& other);
		Angle(const double deg, const double min, const double sec);

		

		double getDegrees() const { return degrees; }
		double getMinutes() const { return minutes; }
		double getSeconds() const { return seconds; }

	private:
		double degrees;
		double minutes;
		double seconds;
	};
	
	bool operator==(const Angle& l, const Angle& r);
	Angle operator+(const Angle& l, const Angle& r);
	Angle operator-(const Angle& l, const Angle& r);
	Angle operator*(const Angle& l, const double factor);
#endif // __HH_LINEAR_ALGEBRA_ANGLE_HH
} // namespace LinearAlgera
// end of file
